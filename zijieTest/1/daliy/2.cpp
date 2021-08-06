#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    long reMin(int n, int k, vector<long> nums) {
        priority_queue<long, vector<long>, less<long>> maxheap;
        for(int i = 1; i < n; i ++) {
            long temp = nums[i] - nums[i-1];
            maxheap.push(temp);
        }

        if(maxheap.top() == 1) return 1;

        for(int i = 0; i < k; i ++) {
            long temp1 = maxheap.top() / 2;
            long temp2 = maxheap.top() - temp1;
            maxheap.push(temp1);
            maxheap.push(temp2);

            maxheap.pop();
            if(maxheap.top() == 1) return 1;

        }

        return maxheap.top();
    }
};

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<long> nums;
    for(int i = 0; i < n; i ++) {
        long temp;
        cin >> temp;
        nums.push_back(temp);
    }

    Solution solution;
    cout << solution.reMin(n, k, nums);

    return 0;
}