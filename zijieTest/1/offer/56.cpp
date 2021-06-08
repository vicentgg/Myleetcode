#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int a = 0,b = 0;
        int ret = 0; // 记录数组中所有数组的异或
        for(auto num : nums) {
            ret ^= num;
        }
        int div = 1;
        while((div & ret) == 0) { //找到两个数的不相同的第一位
            div <<= 1;
        }
        //根据这一位的值 对数组进行分类 且再进行异或运算
        for(auto num : nums) {
            if(num & div) {
                a ^= num;
            }
            else {
                b ^= num;
            }
        }

        return vector<int>{a, b};
    }
};

int main(void) {

}




