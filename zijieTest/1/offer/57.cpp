#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //57-1 找到数组中满足和的两个数
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int s = nums[left] + nums[right];
            if(s > target) right --;
            else if(s < target) left ++;
            else return vector<int>{nums[left], nums[right]};
        }

        return vector<int>();
    }

    //57-2 找到满足和的所有的连续数组
    // 滑动窗口解法 建立双指针
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int i = 1;
        int j = 1;
        int sum = 0;

        while(i <= target/2) {
            if(sum < target) {
                sum += j;
                j ++;
            }
            else if(sum > target){
                sum -= i;
                i ++;
            }
            else {
                vector<int> win;
                for(int k = i; k < j; k ++) win.push_back(k);
                ans.push_back(win);
                sum -= i;
                i ++;
            }
        }
        return ans;
    }

};

int main(void) {

}