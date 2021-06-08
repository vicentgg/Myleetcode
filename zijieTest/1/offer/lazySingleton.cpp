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

Singleton* Singleton::ptr = nullptr;
int Normal::num = 1;

int main(void) {
    Singleton* p = Singleton::getPtr(); //程序结束时 不会调用析构函数 会造成内存泄漏
    
    Normal* a = new Normal();
    delete a;
    return 0;
}