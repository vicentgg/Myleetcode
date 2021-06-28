#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //动态规划
    /*
dp[n,x]表示n个骰子 值为x的概率值
而dp[n,x] = sum(dp[n-1, x-i])(1=< i <=6)
从这个方向开始 会出现越界的现象

换个方向

会有dp[n,x] 与每个dp[n+1, x+i]有关
dp[n+1,x+i] += dp[n,x] / 6.0;
而dp[1]的值已经有了
从这个方向开始推导
每n个骰子 就有5*n+1种结果 则对应的dp的数量

    */
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0/6.0); 
        for(int i = 2; i <= n; i ++) {
            vector<double> temp(5 * i + 1, 0); 
            for(int j = 0; j < dp.size(); j ++) {
                for(int k = 0; k < 6; k ++) {
                    temp[j+k] += dp[j] / 6.0;
                }
            }
            dp = temp;
        }
        return dp;
    }
};

int main(void) {

}