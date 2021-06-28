#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    //59-1 滑动窗口的最大值
    //找到一个数组中 每个长度为k的子序列的最大数

    //1.使用优先队列进行操作
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        typedef pair<int,int> tnum;
        priority_queue<tnum, vector<tnum>, less<tnum>> q; //维护一个优先队列
        int len = nums.size();
        if(len == 0) return vector<int>();

        for(int i = 0; i < k; i ++) {
            q.emplace(nums[i], i);
        }
        vector<int> ans{q.top().first};

        for(int i = k; i < len; i ++) {
            q.emplace(nums[i], i);
            while(q.top().second <= i - k) q.pop();
            ans.push_back(q.top().first);
        }

        return ans;
    }

    //2.使用一个双端单调队列进行操作
    //规则：每次入队列的元素小于队尾元素 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int len = nums.size();
        if(len == 0) return vector<int>();

        //未形成滑动窗口
        for(int i = 0; i < k; i ++) {
            while(!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans{nums[q.front()]};

        for(int i = k; i < len; i ++) {
            while(!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);

            while(q.front() <= i - k) { //当队首坐标超过了范围 则抛弃
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};