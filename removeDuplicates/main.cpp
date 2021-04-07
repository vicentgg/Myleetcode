#include<iostream>
#include<vector>
using namespace std;

/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //双指针解法!!!!!

        if(nums.empty())return 0;
        int length = nums.size();
        int i = 0;

        for(int j = 1; j < length; j ++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;

    }
};

/*
进阶
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {

        //双指针解法
        int length = nums.size();
        if(length <= 2) return length;

        int slow = 2, fast = 2;
        while(fast < length) {
            if(nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow ++;
            }
            fast ++;
        }

        return slow;
    }
};


int main(void) {

}