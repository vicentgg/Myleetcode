#include<iostream>
#include<vector>

using namespace std;

//行程编码解码

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> code;
        int len = nums.size();

        for(int i = 0; i <= len -2; i += 2) {
            for(int j = 0; j < nums[i]; j ++) {
                code.push_back(nums[i + 1]);
            }
        }

        return code;
    }
};

int main(void) {
    
}