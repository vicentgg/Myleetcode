#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;
//
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<bool>> f;
    int n;

    void backtrack(string& s, int start) {
        if(start == n) {
            res.push_back(path);
            return;
        }

        for(int i = start; i < n; i ++) {
            if(f[start][i]) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        f.assign(n, vector<bool>(n, true));

        for(int i = n - 1; i >= 0; -- i) {
            for(int j = i + 1; j < n; ++ j) {
                f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
            }
        }

        backtrack(s, 0);

        return res;
    }
};

int main(void) {

}