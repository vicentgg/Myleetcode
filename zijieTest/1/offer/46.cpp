#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// 将数字翻译为字符串
// 动态规划问题
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int p = 0, q = 0, count = 1;
        for(int i = 0; i < s.size(); i ++) {
            p = q;
            q = count;
            count = 0;
            count += q;
            if(i == 0) continue;
            auto pre = s.substr(i - 1, 2);
            if(pre >= "10" && pre <= "25" ) {
                count += p;
            }
        }

        return count;
    }
};


int main(void) {

}