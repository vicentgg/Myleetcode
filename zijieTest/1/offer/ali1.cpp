#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    vector<vector<int>> returnAns(vector<vector<int>>& nums) {
        int n = nums[0].size();
        vector<int> temp;
        for(int i = 0; i < n / 2; i ++) {
            for(int j = 0; j < n / 2; j ++) {
                swap(nums[i][j], nums[i][n-1-j]);
                swap(nums[i][j], nums[n-1-i][j]);
                swap(nums[n-1-i][j], nums[n-1-i][n-1-j]);
            }
        }
        swap(nums[0][n/2], nums[n/2][0]);
        swap(nums[n/2][0], nums[n][n/2]);
        swap(nums[n][n/2], nums[n/2][n]);

        return nums;

    }
};