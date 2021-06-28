#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero_count = 0;
        for(int i = 0; i < 4; i ++) {
            if(nums[i] == 0) zero_count ++;
            else if(nums[i] == nums[i+1]) return false;
        }
        return nums[4] - nums[zero_count] < 5;
    }
};

int main(void) {

}