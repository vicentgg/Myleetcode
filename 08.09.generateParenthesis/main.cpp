#include<iostream>
#include<vector>

using namespace std;

/*

括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。

*/

class Solution {
private:
    vector<string> ans;    
public:
    vector<string> generateParenthesis(int n) {

        dfs(n, n, "");
        return ans;
    }


    //回溯法
    void dfs(int l, int r, string a) {

        if(l == 0 && r == 0) {
            ans.emplace_back(a);
            return;
        }

        if(l != 0) dfs(l - 1, r, a + '(');
        if(l < r) dfs(l, r - 1, a + ')'); 
    }
};

int main(void) {

}