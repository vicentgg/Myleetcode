#include<iostream>
#include<vector>
using namespace std;


//找到字符串里  最长的回文字符串
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2) return s;

        vector<vector<bool>> dp(len, vector<bool>(len));
        for(int i = 0; i < len; i ++) {
            dp[i][i] = true;
        }

        int max = 1;
        int begin = 0;

        for(int L = 2; L <= len; L ++) {
            for(int i = 0; i < len; i ++) {
                int j = L + i - 1;
                if(j >= len) break;

                if(s[j] == s[i]) {
                    if(j - i < 3) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }

                if(dp[i][j] && L > max) {
                    max = L;
                    begin = i;
                }
            }
        }

        return s.substr(begin, max);      
    }
};