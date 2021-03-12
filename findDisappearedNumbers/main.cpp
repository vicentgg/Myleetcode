#include<iostream>
#include<vector>

using namespace std;

/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，
另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 
你可以假定返回的数组不算在额外空间内。
*/


class Solution {
public:
    //以原数组作为哈希表 按从大到小的顺序排序
    //遍历数组 根据值在对应的哈希表节点加n   记得对值进行求余
    //再次遍历数组  出现值小于n 则该位置对应的哈希表数值 没有在数组中出现过
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty())return nums;

        int length = nums.size();
        for(int i = 0; i < length; i ++) {
            int temp = (nums[i] - 1) % length;
            nums[nums[i]-1] += length;
        }
        for(int i = 0; i < length; i ++) {
            if(nums[i] < length){
                ans.push_back(i+1);
            }
        }

        return ans;

    }
};

int main(void) {



}