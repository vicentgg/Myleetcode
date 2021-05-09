#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //双指针法
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sum;
        int len = nums.size();
        if(len < 3) {
            return sum;
        }

        sort(nums.begin(), nums.end()); //增序

        for(int i = 0; i < len; i ++) {
            if(nums[i] > 0) return sum;

            if( i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1;
            int right = len -1;
            while(left < right) {
                if(nums[left] + nums[right] > -nums[i])right--;
                else if(nums[left] + nums[right] < -nums[i])left++;
                else {
                    vector<int> ret{nums[i],nums[left],nums[right]};
                    sum.push_back(ret);

                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1])left++;
                    while(left < right && nums[right] == nums[right+1])right--;

                }
            }
        }

        return sum;

    }

};

int main(void) {

}