#include<iostream>

using namespace std;

/*

如果一个十进制数字不含任何前导零，且每一位上的数字不是 0 就是 1 ，
那么该数字就是一个 十-二进制数 。例如，101 和 1100 都是 十-二进制数，而 112 和 3001 不是。

给你一个表示十进制整数的字符串 n ，返回和为 n 的 十-二进制数 的最少数目。


思路：就是找到哪位的数字最大 并返回
*/

class Solution {
public:
    int minPartitons(string n) {

        int temp;
        temp = n[0];
        for(int i = 1; i < n.length(); i ++) {
            if(n[i] > temp) temp = n[i];
        }

        return temp-48;

    }
};

int main(void) {

}