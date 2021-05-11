#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//子集2
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backstack(vector<int>& nums, int start) {
        res.push_back(path);

        for(int i = start; i < nums.size(); i ++) {

            if(i > start && nums[i] == nums[i - 1]) continue;  //剪枝 去重
            path.push_back(nums[i]);
            backstack(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        backstack(nums, 0);

        return res;
    }
};

int main(void) {

    return 0;
}
