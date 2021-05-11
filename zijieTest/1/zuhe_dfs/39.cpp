#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//组合
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, int target, int start, int sum) {
        if(sum == target) {
            res.push_back(path);
            return;
        }

        for(int i = start; i < nums.size(); i ++) {
            if(sum + nums[i] > target) break;
            path.push_back(nums[i]);

            backtrack(nums, target, i, sum + nums[i]);
            
            path.pop_back();
        
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, 0);

        return res;
    }
};

int main(void) {

}