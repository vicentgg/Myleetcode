#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //找到和最大的连续子数组
    //动态规划
    //使用新的数组记录 已当前位置为结尾的最大值
    int maxSubArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i ++) {
            nums[i] = nums[i] + nums[i- 1] < nums[i] ? nums[i] : nums[i] + nums[i - 1];
        }
        int max = nums[0];
        for(auto num : nums) {
            max = max > num ? max : num;
        }
        return max;
    }
};

int main(void) {

}