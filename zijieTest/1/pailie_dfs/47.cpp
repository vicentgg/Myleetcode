#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i ++) {
            if(!used[i]) {
                if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;  //剪枝 相等 且上一个数未被使用
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i ++) {
            used.push_back(false);
        }
        sort(nums.begin(), nums.end());
        backtrack(nums);

        return res;
    }
};

int main(void) {

}