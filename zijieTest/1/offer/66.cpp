#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() == 0) return a;
        vector<int> b(a.size());
        int tmp = 1;
        b[0] = 1;

        for(int i = 1; i < a.size(); i ++) {
            b[i] = b[i-1] * a[i-1];
        }

        for(int i = a.size() - 2; i >= 0; i --) {
            tmp *= a[i+1];
            b[i] *= tmp;
        }

        return b;
    }
};

int* newInt(int value) {
    int *p = new int;
    
    *p = value;

    return p;
}

int main(void) {
    const char *p = "hello";
    char q[6] = "hello";
    int *tmp = newInt(20);
    cout << sizeof(p) << endl;
    cout << sizeof(q) << endl;
    cout << sizeof(tmp) << endl;
    cout << p << endl;
    cout << q << endl;
    cout << tmp << endl;

    delete tmp;

    return 0;
}