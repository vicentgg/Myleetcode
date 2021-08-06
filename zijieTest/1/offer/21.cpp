#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return nums;

        //i遍历数组  j遇到偶数便停下来
        for(int i = 0, j = 0; i < len; i ++) {

            if(nums[i] % 2 == 1 && i != j) {
                swap(nums[i], nums[j]);
                ++ j;
            }
            if(nums[j] % 2 == 1) ++ j;

        }    

        return nums;    
    }

    //当奇数或者偶数之间的顺序 不能发生改变时
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return nums;

        for(int i = 1; i < len; i++) {
            if(nums[i] % 2 == 1) {
                int temp = nums[i];
                int j;
                for(j = i - 1; j >= 0 && nums[j] % 2 == 0; j --) {
                    nums[j+1] = nums[j];
                }
                nums[j+1] = temp;
            }
        }

        return nums;
    }
};

int main(void) {
    
}