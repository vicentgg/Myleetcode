#include<iostream>
#include<vector>

using namespace std;


/*
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。
说明：解集不能包含重复的子集。
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        //动态规划
        //[1,2,3]的子集是在[1.2]的所有子集基础上加3 连同原本的子集组成的
        //F[N] = F[N-1][I] + (F[N-1][I]+3)
        vector<vector<int>> ans;

        vector<int> start = {};

        ans.push_back(start);

        for(int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            int len = ans.size();
            for(int j = 0; j < len; j ++) {
                vector<int> temp = ans[j];
                temp.push_back(num);
                ans.push_back(temp);
            }
        }

        return ans;



    }
};

int main(void) {
    
}