#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //暴力搜索
    int search(vector<int>& nums, int target) {
        int count = 0;

        for(auto num : nums) {
            if(num > target) break;
            if(num == target) count ++;
        }

        return count;
        
    }

    //有序数组 可以用二分查找
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) //找到左边界
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if(nums[left] != target) return 0;
        int l_num = left;

        left = 0;
        right = nums.size() - 1;
        while(left < right) { //找到右边界
            int mid = left + (right + 1 - left) / 2;
            if(nums[mid] > target) right= mid - 1;
            else left = mid;
        }

        return left - l_num + 1;
    }

    //53-2
    //二分查找
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int m;
        while(i <= j) {
            m = j + (i - j) / 2;
            if(nums[m] == m) i = m + 1;
            else j = m - 1;
        }

        return i;
    }

    
};

int main(void) {

}