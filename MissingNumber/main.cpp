#include<iostream>
#include<vector>

using namespace std;

/*
给定一个包含 [0, n] 中 n 个数的数组 nums ，
找出 [0, n] 这个范围内没有出现在数组中的那个数
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int num_count = (length + 1) * length;
        for(int i = 0; i < length; i ++) {
            num_count -= nums[i];
        }
        return num_count;
    }
};

int main(void) {


}