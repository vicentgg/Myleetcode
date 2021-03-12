#include<iostream>

using namespace std;


extern const int bufferSize = 512; //定义一个常量 且能被其他文件访问


int main(void) {
    unsigned u = 10;
    int i = -42;

    cout << i + i << endl;
    cout << u + i << endl;
}