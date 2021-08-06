#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    string reStr(string& str) {
        int len = str.size() - 1;
        if(len <= 1) return str;

        int right = 1, left = 0;
        while(right < len) {
            while(str[right] != str[left] && right < len) {
                right ++;
                left ++;
            }

            int flag = false;
            while( (str[right] == str[left] || str[right] == '\0') && right < len ) {
                right ++;
                flag = true;
            }

            if(flag) {
                for(int i = left; i < right; i ++) str[i] = '\0';
                while(str[left] == '\0') left --;
                if(left < 0) {
                    left = right;
                    right ++;
                }
            }
        }

        string ans;
        for(auto c : str) {
            if(c != '\0') ans += c;
        }
        return ans;

    }
};

int main(void) {
    string s;
    cin >> s;
    Solution solution;
    cout << solution.reStr(s);

    return 0;
}