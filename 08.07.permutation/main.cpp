#include<iostream>
#include<vector>

using namespace std;

/*
无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。
*/

class Solution {
public:

    //动态规划
    vector<string> permutation(string S) {
        int length = S.length();
        vector<string> res;

        if(length <= 0) {
            return res;
        }
        string a = S.substr(0,1);
        res.push_back(a);

        for(int i = 1; i < length; i ++) {
            int count = res.size();
            for(int j = 0; j < count; j ++) {
                string temp = res[j];
                int len = temp.length();
                for(int k = 0; k < len; k ++) {
                    string t = temp.substr(0,k) + S[i] + temp.substr(k);
                    res.push_back(t);
                }
                res.push_back(temp + S[i]);
            }
            res.erase(res.begin(), res.begin() + count);
        }

        return res;
    }

};

int main(void) {

}