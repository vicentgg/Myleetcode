#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res += n & 1; //与n的二进制最右一位进行与运算 
            n >>= 1; // n 右移一位
        }

        while(n) {
            res += 1;
            n &= n - 1; //与 n-1 进行与运算 n的二进制有多少个1  就只能计算多少次 便到0
        }
        return res;
    }
};

int main(void) {
     
}