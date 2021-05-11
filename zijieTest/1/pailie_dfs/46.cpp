#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//全排列
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used; //记录已经使用过的数组

    void backtrack(vector<int>& nums) {

        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i ++) {
            if(!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i ++) {
            used.push_back(false);
        }
        backtrack(nums);

        return res;
    }
};

int main(void) {

}