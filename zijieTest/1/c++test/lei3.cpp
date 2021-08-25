#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string reAns(vector<string>& strs, string temp, int n) {
        string ans;
        unordered_map<string, string> mp;
        
        for(auto str : strs) {
            string key, value;
            int len = str.size();
            int i = 0;
            while(i < len && str[i] == ' ') i ++;
            if(i == len) continue;
            if(str[i] == '#') continue;

            while(i < len && str[i] != ' ' && str[i] != '=') key += str[i++];
            while(i < len && str[i] == ' ')

            if(i == len) return "ERROR";
        }

        return ans;
    }
};

int main(void) {
    int num;
    cin >> num;

    vector<string> strs(num);
    for(int i = 0; i < num; i ++) cin >> strs[i];

    string temp;
    cin >> temp;
    Solution solution;

    cout << solution.reAns(strs, temp, num);

    return 0;

}