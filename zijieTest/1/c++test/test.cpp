#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> returnAns(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        vector<int> temp;
        temp.push_back(nums[0][0]);
        temp.push_back(nums[0][1]);
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i][0] > temp[1]) {
                ans.push_back(temp);
                temp = nums[i];
            }
            else if(nums[i][0] < temp[1] && nums[i][1] > temp[1]) {
                temp[1] = nums[i][1];
                ans.push_back(temp);
            }
        }

        if(temp == nums[nums.size() - 1]) ans.push_back(temp);

        return ans;
    }
};

int main(void) {
    vector<vector<int>> nums;
    

    Solution solution;

}