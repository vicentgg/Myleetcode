#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string longStr(string& str) {
        int len = str.size();
        if(len == 1) return str;
        vector<int> dp(len);
        string ans;
        unordered_map<char,int> map;

        dp[0] = 1;
        int max = 0;
        map[str[0]] = 1;
        for(int i = 1; i < len; i ++) {
            if(map[str[i]] == 0) {
                dp[i] = dp[i - 1] + 1;
                map[str[i]] = 1;
            }
            else {
                dp[i] = 1;
                map.clear();
                map[str[i]] = 1;
            }
            if(dp[i] > dp[max]) max = i;
        }

        ans = str.substr(max - dp[max] + 1, max);
        return ans;

    }
};

int main(void) {

}