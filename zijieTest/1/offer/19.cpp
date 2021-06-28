#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//19.正则表达式匹配
//动态规划
//s[:]
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1;
        int n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));

        //初始化 状态数组
        dp[0][0] = true;;
        for(int j = 2; j < n; j += 2) dp[0][j] = dp[0][j-2] && p[j-1] == '*';
 

        for(int i = 1; i < m; i ++) {
            for(int j = 1; j < n; j ++) {
                if(p[j-1] == '*') {
                    //1.将*看成前一个字符零次出现 且以j-3字符为结尾的字符串满足匹配
                    //2.将*看成前一个字符两次出现
                    //3.将.多出现一次
                    if(dp[i][j-2] || dp[i-1][j] && ( s[i-1]==p[j-2] || p[j-2] == '.')) dp[i][j] = true;
                }
                else {
                    //当不是*时 只当两个字符相等 或者 j-1字符为.时
                    if(dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')) dp[i][j] = true;
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main(void) {

}