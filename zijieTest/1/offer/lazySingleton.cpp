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

class Normal {
private:
    static int num;
public:
    Normal() {cout << "n_s" << endl;}
    ~Normal() {cout << "n_e" << endl;}
    Normal(const Normal&);
    Normal& operator=(const Normal&);
};

class Daily {
public:
    Daily() {cout << "d_s" << endl;}
    ~Daily() {cout << "d_e" << endl;} 
};


Singleton* Singleton::ptr = nullptr;
Singleton::Deletor Singleton::deletor;

int Normal::num = 1;


int main(void) {
    Normal te;
    Daily da;
    Singleton* p = Singleton::getPtr(); //程序结束时 不会调用析构函数 会造成内存泄漏
    
    return 0;
}