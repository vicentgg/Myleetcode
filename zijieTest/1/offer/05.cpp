#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        for(int i = 0; i < s.length();) {
            if(s[i] == ' ') {
                s.erase(i, 1);
                s.insert(i, "%20");
                i += 3;
            }
            else {
                i ++;
            }
        }
        
        return s;
    }
};

int main(void) {

}