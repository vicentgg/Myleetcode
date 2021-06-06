#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long start = 1; //起始数字
        int digit = 1; //数字位数
        long count = 9; //当前位数 数字和

        while(n > count) {
            start *= 10;
            digit += 1;
            n -= count;
            count = digit * start * 9;
        }
        long num = start + (n - 1) / digit; //找到当前的数字
        int bitNum = (n - 1) % digit;
        string numString = to_string(num);
        return numString[bitNum] - '0';
    }
};

int main(void) {

}