#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //58-1 翻转语句 单词不反转
    //双指针法
    string reverseWords(string s) {
        if(s.empty()) return s;
        int right = s.size() - 1;
        int left = s.size() - 1;
        string ans = "";

        while(left >= 0) {
            while(s[left] == ' ') {
                left --;
                right --;
                if(left < 0) break;
            }
            if(left < 0) break;

            while(s[left] != ' ') {
                left --;
                if(left < 0) break;
            }
            ans.append(s.substr(left + 1, right - left) + ' ');
            right = left;
        }

        return ans.substr(0, ans.size()-1);
     }

     //58-2 左旋转字符串 将字符串后面一部分的字符放到前面字符的前面
     string reverseLeftWords(string s, int n) {
         s += s;
         return s.substr(n, s.size() / 2);
     }
};


int main(void) {

}