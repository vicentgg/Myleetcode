#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //对数组中每个数字的二进制的每个1进行统计  
    //则所有的重复统计数都是3的倍数  
    //不是3的倍数的位数 就是要找的数字的二进制1所在的位数
    int singleNumber(vector<int>& nums) {
        vector<int> bitCount(32,0); //位数统计数组
        for(auto num : nums) {
            for(int i = 0; i < 32; i ++) {
                bitCount[i] += num & 1;
                num >>= 1; 
            }
        }
        int res = 0, m = 3;
        for(int i = 0;i < 32; i ++) {
            res <<= 1;
            res |= bitCount[31 - i] % m;
        }
        
        return res;
    }
};

int main(void) {

}