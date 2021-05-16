#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    //先排序再遍历
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] == nums[i - 1]) return nums[i];
        }

        return - 1;
    }

    //使用哈希表
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> record;
        for(auto num : nums) {
            if(record[num]) return num;
            record[num] = true;
        }

        return -1;
    }

  
};

int main(void) {

}