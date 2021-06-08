#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:

    //使用哈希表
    char firstUniqChar(string s) {
        char ans = ' ';
        vector<char>keys;
        unordered_map<char, bool> mp;
        for(auto c : s) {
            if(mp.find(c) == mp.end()) {
                keys.push_back(c);
            }
            mp[c] = mp.find(c) == mp.end(); //找到一次为true  找到多次为false
        }
        for(auto c : keys) {
            if(mp[c]) {
                ans = c;
                break;
            }
        }
        return ans;
    }

    
};

int main(void) {

}