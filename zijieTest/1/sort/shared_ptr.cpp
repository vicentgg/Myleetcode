#include<iostream>
#include<mutex>

using namespace std;

//定义一个个人共享指针
template<typename T>
class Shared_ptr {
private:
    int* count; //引用计数模块
    T* ptr; //调用外部指针
    mutex* pMutex; //互斥锁

    //释放维护资源
    void release() {
        bool flag =  false;

        pMutex ->lock();
        if(--(*count) == 0) {
            delete ptr;
            delete count;
            flag = true;
        }
        pMutex ->unlock();


        if(flag) delete pMutex;
    }

    //增加引用计数
    void addCount() {
        pMutex ->lock();
        (*count)++:
        pMutex ->unlock():
    }

public:
    //构造函数
    Shared_ptr(T* p = nullptr) : ptr(p), count(new int(0)), pMutex(new mutex) {}

    //析构函数
    ~Shared_ptr() {
        release();
    }

    //拷贝构造函数
    Shared_ptr(const Shared_ptr& sp) : ptr(sp.ptr), count(sp.count), pMutex(sp.pMutex) {
        addCount(); //增加引用计数
    }

    //拷贝赋值函数
    Shared_ptr& operator=(const Shared_ptr& sp) {
        if(ptr != sp.ptr) {
            release();

            ptr = sp.ptr;
            count = sp.count;
            pMutex = sp.pMutex;
            addCount();

            return *this;
        }
    }

    //返回引用计数
    int reCount() {
        return *count;
    }

    T* get() {
        return ptr;
    }

    T& operator*() {
        return *ptr;
    }

    T& operator->() {
        return ptr;
    }
};

