#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    //矩形覆盖
    //动态规划
    //dp[1] = 1, dp[2] = 2, dp[3] = dp[1] + dp[2]
    //则有dp[n] = dp[n-1] + dp[n-2]
    int rectCover(int number) {
        if(number <= 2) return number;
        int a = 1;
        int b = 2;
        int sum;
        for(int i = 2; i < number; i ++) {
            sum = a + b;
            a = b;
            b = sum;
        }

        return sum;
    }
};

