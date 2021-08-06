#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int len1 = pushed.size();
        int len2 = pushed.size();
        if(len1 == 0 && len2 == 0) return true;

        int i = 0;
        for(auto a1 : pushed) {
            s.push(a1);
            while(!s.empty() && s.top() == popped[i]) {
                s.pop();
                i ++;
            }
        }

        return s.empty();
    }
};

int main(void) {
    
}