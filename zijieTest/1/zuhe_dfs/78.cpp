#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//子集1
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    //回溯
    void backtrack(vector<int> nums, int start) {
        res.push_back(path);

        for(int i = start; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);

        int l = nums.size();
        for(int i = 0; i < l; i ++) {
            int len = ans.size();
            for(int j = 0; j < len; j ++) {
                vector<int> t = ans[j];
                t.push_back(nums[i]);
                ans.push_back(t);
            }
        }

        return ans;
    }
};

int main(void) {
    return 0;
}