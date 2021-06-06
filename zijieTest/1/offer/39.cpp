#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //使用哈希表进行统计
        unordered_map<int,int> map;
        for(auto num : nums) {
            if(++map[num] > nums.size() / 2) return num;
        }
        return -1;

        //排序
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];

        //投票
        int x; //记录当前众数
        int votes = 0;  //记录当前众数的票数
        for(auto num : nums) {
            if(votes == 0) x = num;

            votes += num == x ? 1 : - 1; //当前数是不是众数  
        }

        int count = 0;
        for(auto num : nums) {
            if(num == x) count ++;
            if(count > nums.size() / 2) return x;
        }

        return -1;
    }
};

int main(void) {

}