#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Base {
public:
    Base();
    ~Base();
    virtual void func();
};

Base::Base() {
    cout << "new Base" << endl;
}

Base::~Base() {
    cout << "del Base" << endl;
}

void Base::func() {
    cout << "this is Base" << endl;
}


class Test : public Base {
private:
    int size;
    char *p;
public:
    //基础的四个默认函数
    Test();
    Test(const char *t); 
    ~Test();
    Test(const Test &t);
    Test& operator=(const Test &t);
    void func();
};

Test::Test() {
    size = 0;
    p = nullptr;
}

Test::Test(const char *t) {
    size = 
}


void Test::func() {
    cout << "this is Test" << endl;
}

int main(void) {

}