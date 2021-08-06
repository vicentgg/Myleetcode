#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Base {
private:
    int val;
public:
    Base(int x) : val(x) {}
    virtual void func1() {
        cout << "Base_v" << endl;
    }
    void func2() {
        cout << "Base_val" << val << endl;
    }
};

class Drived : public Base {
public:
    Drived(int x) : Base(x) {}
    void func1() {
        cout << "Drived_v" << endl;
    }
    void func2() {
        cout << "Drived_val"  << endl;
    }
};

int main() {
    Base base(1);
    Drived drived(2);
    base.func1();
    base.func2();
    drived.func1();
    drived.func2();
    drived.Base::func1();
    drived.Base::func2();

    Base* p = new Drived(3);
    p ->func1();
    p ->func2();
    p ->Base::func1();
    p ->Base::func2();

    return 0;
}