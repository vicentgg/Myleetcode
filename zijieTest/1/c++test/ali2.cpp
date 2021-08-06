#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> reAns(vector<int>& loc, vector<pair<int,int>>& nums, vector<bool>& prime, int n, int q) {
        vector<vector<bool>> temp(n, vector<bool>(n, false));
        vector<string> ans;
        for(int i = 0; i < n; i ++) {
            for(int j = i; j < n; j ++) {
                int max_num = max(loc[i], loc[j]);
                int min_num = min(loc[i], loc[j]);
                if(max_num % min_num == 0 && prime[max_num/min_num]) {
                    temp[i][j] = true;
                    temp[j][i] = true;
                }       
            }
        }

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                for(int k = 0; k < j; k ++) {
                    if(temp[i][j] == false && temp[i][k] && temp[k][j]) {
                        temp[i][j] = true;
                        temp[j][i] = true;
                    } 
                }
            }
        }

        for(int i = 0; i < q; i ++) {
            if(temp[nums[i].first - 1][nums[i].second - 1]) ans.emplace_back("ok");
            else ans.emplace_back("no");
        }

        return ans;

    }
};

int main(void) {
    int n, q;
    cin >> n >> q;
    vector<int> loc(n);
    for(int i = 0; i < n; i ++) cin >> loc[i];

    vector<pair<int, int>> nums(q);
    for(int i = 0; i < q; i ++) cin >> nums[i].first >> nums[i].second;

    Solution solution;

    vector<bool> prime(100001, true);
    for(int i = 2; i <= 50000; i ++) {
        if(prime[i]) {
            for(int j = 2; j * i < 100001; j ++) {
                prime[j*i] = false;
            }
        }
    }

    vector<string> ans = solution.reAns(loc, nums, prime, n, q);
    for(int i = 0; i < q; i ++) {
        cout << ans[i] << endl;
    }

    return 0;
}