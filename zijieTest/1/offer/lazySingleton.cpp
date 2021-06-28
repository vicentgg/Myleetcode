#include<iostream>
#include<vector>
#include<algorithm>
#include<memory> //

using namespace std;

//单例模式 懒汉版
class Singleton {
private:
    static Singleton* ptr;
private:
    Singleton() {cout<<"start"<<endl;}
    ~Singleton() {cout<<"end"<<endl;}
    Singleton(const Singleton&); //拷贝
    Singleton& operator=(const Singleton&); //赋值
private:
    class Deletor { //定义一个嵌套类
	public:
		~Deletor() {
			if(Singleton::ptr != NULL)
				delete Singleton::ptr;
		}
	};
	static Deletor deletor;
public:
    static Singleton* getPtr() {
        if(ptr == NULL) {
            ptr = new Singleton();
        }
        return ptr;
    }
};

//单例模式  
class Normal {
private:
    static int num;
public:
    Normal() {cout << "n_s" << endl;}
    ~Normal() {cout << "n_e" << endl;}
    Normal(const Normal&);
    Normal& operator=(const Normal&);
};

Singleton* Singleton::ptr = nullptr;
Singleton::Deletor Singleton::deletor;

int Normal::num = 1;


int main(void) {
    Singleton* p = Singleton::getPtr(); //程序结束时 不会调用析构函数 会造成内存泄漏
    
    Normal* a = new Normal();
    delete a;

    Normal te;

    return 0;
}