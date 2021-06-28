#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //不能使用四则运算 进行求和
    //将两数之和 变为a^b + (a&b) << 1  但是还是有相加操作
    //则需要加一个循环 使(a&b) << 1为0
    int add(int a, int b) {
        int yihuo;
        int yu;
        while(b != 0) {
            yihuo = a ^ b;
            yu = ((unsigned int)(a & b) << 1);
            a = yihuo;
            b = yu;
        }

        return a;
    }
};

int main(void) {

}