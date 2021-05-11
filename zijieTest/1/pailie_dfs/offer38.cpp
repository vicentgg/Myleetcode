#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> res;
    string path;
    vector<bool> used;

    void backtrack(string s) {
        
        if(path.size() == s.length()) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < s.length(); i ++) {
            if(!used[i]) {
                if(i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;
                path.push_back(s[i]);
                used[i] = true;
                backtrack(s);
                used[i] = false;
                path.pop_back();
            }
        }

    }

    vector<string> permutation(string s) {        
        sort(s.begin(), s.end());
        for(int i = 0; i < s.length(); i ++) {
            used.push_back(false);
        }

        backtrack(s);

        return res;
    }
};

int main(void) {
    
}