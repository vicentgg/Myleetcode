#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//股票的最大利润
class Solution {
public:
    //动态规划
    //dp[i]表示当前日期的最大利润 
    //dp[i] = dp[i-1] + (n[i]-n[i-1])  仅当 该值大于0  否则dp[i] = 0
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int max = 0;
        int temp = 0;
        for(int i = 1; i < prices.size(); i ++){
            if(prices[i] - prices[i-1] + temp > 0) temp = prices[i] - prices[i-1] + temp;
            else temp = 0;
            if(temp > max) max = temp;
        }

        return max;
    }
};

int main(void) {

}
