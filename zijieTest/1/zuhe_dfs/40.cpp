#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//组合  数组有重复元素 且每个元素只能使用一次
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, int target, int sum, int start) {
        if(sum == target) {
            res.push_back(path);
            return;
        }

        for(int i = start; i < nums.size(); i ++) {
            if(sum + nums[i] > target) return;  //已经超过了 代表后面都不行 进行剪枝
            if(i > start && nums[i] == nums[i - 1]) continue;  // 如果有重复 就跳过这个点
            path.push_back(nums[i]);

            backtrack(nums, target, sum + nums[i], i + 1);

            path.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, 0);

        return res;
    }
};