#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int reAns(int n, int t1, int t2, int t3, int t4, vector<int>& out) {
        if(n == 1) return 0;
        vector<pair<int,int>> dp(n);

        dp[0].first = 0;
        dp[0].second = t4;
        for(int i = 1; i < n; i ++) {
            if(out[i] - out[i-1] > 1) {
                dp[i].second = dp[i-1].second + t3;
                dp[i].first = dp[i-1].second + t3 + t4;
            }
            else if(out[i] - out[i-1] == 1) {
                dp[i].first = min(dp[i-1].first + t2, dp[i-1].second + t3 + t4);
                dp[i].second = min(dp[i-1].second + t3, dp[i-1].first + t2 + t4);
            }
            else if(out[i] - out[i-1] == 0) {
                dp[i].first = min(dp[i-1].first + t1, dp[i-1].second + t1 + t4);
                dp[i].second = min(dp[i-1].second + t1, dp[i-1].first + t1 + t4);
            }
            else if(out[i] - out[i-1] == -1) {
                dp[i].first = min(dp[i-1].first + t3, dp[i-1].second + t2 + t4);
                dp[i].second = min(dp[i-1].second + t2, dp[i-1].first + t3 + t4);
            }
            else if(out[i] - out[i-1] < -1) {
                dp[i].first = dp[i-1].first + t3;
                dp[i].second = dp[i-1].first + t3 + t4;
            }
        }

        return min(dp[n-1].first, dp[n-1].second);
        
    }
};

int main(void) {
    int n, t1, t2, t3, t4;
    cin >> n >> t1 >> t2 >> t3 >> t4;

    vector<int> out(n);
    for(int i = 0; i < n; i ++) cin >> out[i];

    Solution solution;
    cout << solution.reAns(n, t1, t2, t3, t4, out);

    return 0;

}