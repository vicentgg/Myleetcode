#include<iostream>
#include<algorithm>

using namespace std;

//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
//请定义一个函数实现字符串左旋转操作的功能。
//比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。


class Solution {
public:

    //方法1  三重旋转
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());

        return s;
    }

    //方法2 拼接字符串
    string reverseLeftWords2(string s, int n) {
        return s.substr(n, s.size()-n) + s.substr(0, n);
    };

};

int main(void) {

}