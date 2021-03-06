#include<iostream>
#include<vector>

//一维数组动态和
using namespace std;

class Solution {
public:
    //& 引用
    vector<int> runningSum(vector<int>& nums){

        vector<int> countSum(nums.size());//新建vector
        countSum[0] = nums[0];
        for(int i = 1, len = nums.size(); i < len; i ++){
            countSum[i] = countSum[i-1] + nums[i];
        }

        return countSum;

    }
    
};

int main(void){

}
