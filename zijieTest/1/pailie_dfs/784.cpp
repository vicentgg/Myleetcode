#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<int> loc;  //记录字母下标数组
    vector<int> path;  //下标数组的子集
    string str; 

    void backtrack(vector<int>& nums, int start, string s) {

        str = s;  
        for(auto p : path) {
            if(islower(str[p])) str[p] = toupper(str[p]); 
            else str[p] = tolower(str[p]);        
        }
        res.push_back(str);

        for(int i = start; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, s);
            path.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        for(int i = 0; i < s.length(); i ++) {
            if(isalpha(s[i]))loc.push_back(i);
        }

        
        backtrack(loc, 0, s);

        return res;

    }  
};

int main(void) {

}