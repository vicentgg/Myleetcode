#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//组合
//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(int n, int k, int start) {
    
        if(path.size() == k) {
            res.push_back(path);
            return;
        }

        for(int i = start; i <= n + 1 - k + path.size(); i ++) { //剪枝
            path.push_back(i);
            
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        if(n < 1 || n < k || k < 1) return res;    

        backtrack(n, k, 1);
        return res;
    }
};

int main(void) {

}
