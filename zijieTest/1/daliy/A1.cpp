#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int reAns(vector<int>& nums, int n) {
        unordered_map<int,int> mp;
        for(auto num : nums) {
            if(mp.find(num) == mp.end()) mp[num] = 1;
            else mp[num] += 1;
        }
        for(int i = 0; i < n; i ++) {
            if(mp[nums[i]] == 1) return i;
        }

        return -1;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];

    Solution solution;
    cout << solution.reAns(nums, n);

    return 0;

}