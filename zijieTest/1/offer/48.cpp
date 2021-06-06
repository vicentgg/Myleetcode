#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<math.h>

using namespace std;

class Solution {
public:
    //动态规划 
    //以当前位置为结尾的字符串的最大长度f[i] = f[i-1] + 1 (w不在f[i-1]内) 如果在就等于1
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int pre = 0;
        int temp;

        for(int i = 0; i < s.length(); i ++) {
            temp = pre;
            for(int j = i - 1; j >= i - pre; j --) {
                if(s[j] == s[i]){
                    temp = i - j - 1;
                    break;
                }
            }
            temp += 1;
            pre = temp;
            max = max > temp ? max : temp;

        }

        return max;
    }

    //双指针法和哈希表
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int right = 0, left = 0;
        vector<int> record(128, -1);
        while (right < s.length())
        {
            if(record[s[right]] != -1) {
                left = record[s[right]] + 1 > left ? record[s[right]] + 1 : left;
            }
            record[s[right]] = right;
            int ans = right - left + 1;
            max = max > ans ? max : ans;
            right ++;
        }

        return max;
    }

};

int main(void) {

}