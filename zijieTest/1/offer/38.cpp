#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
private:
    vector<string> ans;
    string path;
public:  
    void backtrack(string s, vector<int>& vis) {
        if(path.size() == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < s.size(); i ++) {
            if(vis[i]) continue;

            path.push_back(s[i]);
            vis[i] = 1;
            backtrack(s, vis);
            vis[i] = 0;
            path.pop_back();

            while(i + 1 < s.size() && s[i+1] == s[i]) i ++;
        }
    }

    vector<string> permutation(string s) {
        if(s.size() == 0) return ans;
        sort(s.begin(), s.end());
        vector<int> vis(s.size(), 0);
        backtrack(s, vis);
        return ans;
    }
};

int main(void) {

}