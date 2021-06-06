#include<iostream>

using namespace std;

class A {
private:
    static int n;
    int m;
public:
    A(int m) : m(m) {}
    static void fun1() {
        cout << n << endl;
    } 
    void fun2() {
        cout << m << endl;
    }
};
int A :: n = 1;

int main(void) {
    A::fun1();
    A a(3);
    a.fun1();
    a.fun2();

    return 0;
}