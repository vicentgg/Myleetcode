#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;


//43 求出1~n中n个整数 1出现的次数
//每一位的数上1出现的次数 都与高位数 低位数相关
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0; //统计1的个数
        int high = n / 10; //高位
        int low = 0; //低位
        int cur = n % 10; //当前位
        long digit = 1;  //记录当前位的阶

        while (high != 0 || cur != 0) {
            if(cur == 0) count += high * digit;
            else if(cur == 1) count += high * digit + low + 1;
            else count += (high + 1) * digit;
            low += cur * digit;
            cur = high % 10;
            high = high / 10;
            digit *= 10;
        }
        
        return count;
    }
};

int main(void) {

}