#include<iostream>
#include<stdlib.h>
using namespace std;

//空间配置器
template<typename T>
struct Myalloc {
    //申请空间
    T* allocator(size_t size) {
        return (T*)malloc(size * sizeof(T));
    }
    //释放空间
    void delallocator(T* p) {
        free(p);
    }
    //调用构造函数
    void counstruct(T* p, const T& val) {
        p = new T(val);
    }
    //调用析构函数
    void destory(T* p) {
        p ->~T();
    }
};

//vec类实现
template<typename T, typename Alloc = Myalloc<T>>
class Vector {
private:
    T* first;
    T* last;
    T* end;
    Alloc alloc;

    //内存扩容
    void expand() {
        size_t len = last - first;
        size_t size = end - first;

        T* temp = alloc.allocator(2*size); //申请两倍的空间
        for(int i = 0; i < len; i ++) alloc.construct(temp + i, first[i]);  //拷贝元素

        des(); //释放原来的内存

        first = temp;
        last = first + len;
        end = first + 2*size;
    }

    //释放内存
    void des() {
        for(T* p = first; p != last; p ++) alloc.destory(p); //析构元素
        alloc.delallocator(first); //释放内存

        first = nullptr;
        last = nullptr;
        end = nullptr;
    }

    //拷贝元素
    void copy(const Vector& vec) {
        size_t len = vec.last - vec.first; //数组长度
        size_t size = vec.end - vec.first; //数组空间大小

        first = alloc.allocator(size); //先申请一样大小的空间
        for(int i = 0; i < len; i ++) alloc.construct(first + i, vec.first[i]); //再调用构造函数

        last = first + len;
        end = first + size;
    }
public:
    //构造函数
    Vector(size_t size = 1) {
        first = alloc.allocator(size); //申请内存空间
        last = first;
        end = first + size;
    }

    //析构函数
    ~Vector() {
        des();
    }

    //拷贝构造函数
    Vector(const Vector& vec) {
        copy(vec);
    }

    //拷贝赋值函数
    Vector& operator=(const Vector& vec) {
        if(*this == vec) return *this;

        if(first != nullptr) {
            des();
        }

        copy(vec);
        return *this;
    }

    bool empty()const {
        return first == last;
    }

    bool full()const {
        return last == end;
    }

    size returnSize()const {
        return last - first;
    }
    //重写中括号
    T& operator[](int index)const {
        if(index >= 0 && index < returnSize()) return first[index];
        return -1;
    }

    //在尾部插入数据
    void push_back(const T& val) {
        if(full()) expand();
        alloc.construct(last, val);
        last ++:
    }

    //在尾部弹出数据
    void pop_back() {
        if(empty()) return;
        last --;
        alloc.destory(last);
    }
};
