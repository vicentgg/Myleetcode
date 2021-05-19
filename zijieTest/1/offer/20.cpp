#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public: 
    bool isNumber(string s) {
        string ans = "";
        int len = s.length();
        if(len == 0) return false;

        int first = 0;
        int last = len - 1;

        while(first < len && s[first] == '\0') first ++;
        while(last > 0 && s[last] == '\0') last --;

        ans = s.substr(first, last - first + 1); //减去空格
        if(ans.size() == 0) return false;
        for(int i = 0; i < ans.size(); i ++) 

    }
};

int main(void) {

}