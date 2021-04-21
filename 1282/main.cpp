#include<iostream>
#include<vector>
#include<unordered_map>
 
using namespace std;

/*
有 n 位用户参加活动，他们的 ID 从 0 到 n - 1，每位用户都 恰好 属于某一用户组。给你一个长度为 n 的数组 groupSizes，其中包含每位用户所处的用户组的大小，请你返回用户分组情况（存在的用户组以及每个组中用户的 ID）。

你可以任何顺序返回解决方案，ID 的顺序也不受限制。此外，题目给出的数据保证至少存在一种解决方案。
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        //建立哈希表
        unordered_map<int,vector<int>> groups;
        for(int i = 0; i < groupSizes.size(); i ++) {
            groups[groupSizes[i]].push_back(i);
        }


        vector<vector<int>> ans;
        //遍历哈希表
        for(auto group = groups.begin(); group != groups.end(); ++group) {
            const int& gsize = group->first;
            vector<int>& users = group->second;
            for(auto iter = users.begin(); iter != users.end(); iter = next(iter, gsize)) {
                vector<int> temp(iter, next(iter, gsize));
                ans.push_back(temp);
            }
        }

        return ans;

    }
};

int main(void) {

}