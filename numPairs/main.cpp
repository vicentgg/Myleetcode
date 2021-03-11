#include<iostream>
#include<vector>
using namespace std;

/*
给你一个整数数组 nums 。

如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。

返回好数对的数目


*/


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int numPairsCount = 0;
        int length = nums.size();
        vector<int> numCount(100,0);

        for(int i = 0; i < length; i ++) {
            numCount[nums[i]-1] ++;
        }

        for(int i  = 0 ; i < 100; i ++) {
            int temp = numCount[i];
            if(temp > 1){
                numPairsCount += temp * (temp - 1) / 2;
            }
        }


        //更精简的方法
        //当一个数出现两次的时候 就会加1 并进行统计
        for(int i = 0; i < length; i ++) {
            numPairsCount += numCount[nums[i] - 1] ++;
        };



        return numPairsCount;
    }


};

int main(void) {

}