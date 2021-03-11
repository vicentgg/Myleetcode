#include<iostream>
#include<vector>

using namespace std;


/*
给你一个 m x n 的整数网格 accounts ，
其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。
返回最富有客户所拥有的 资产总量 。

客户的 资产总量 就是他们在各家银行托管的资产数量之和。
最富有客户就是 资产总量 最大的客户。

*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for(int i = 0, len = accounts.size(); i < len; i ++) {
            int temp = 0;
            for(int j = 0, len = accounts[i].size(); j < len; j ++) {
                temp +=accounts[i][j];
            }
            if(temp > max)max = temp;
        }

        return max;
    }
};

int main(void) {

}