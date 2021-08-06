#include<iostream>
#include<vector>
#include<stack>

using namespace std;
//输出括号匹配最长的字符串长度
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return 0;
        stack<int> st;

        st.push(-1); //先加入一个预先值-1
        int len = 0;
        int max = 0;

        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == '(') st.push(i);  //当遇到左括号时，就入栈下标
            else if(s[i] == ')') { //遇到右括号时，先弹栈，判断栈是否为空
                st.pop();
                if(st.empty()) { //为空时  代表连续匹配的子串在这里断掉了 则需要记录新的下标
                    st.push(i);
                }
                else len = i - st.top(); //不为空 计算字串的长度

                max = max > len ? max : len;
            }
        }

        return max;
        
    }
};

int main(void) {

}