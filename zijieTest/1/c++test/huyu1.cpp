#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> digits{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    vector<char> lastNums{'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    int path;
    int sum;
    void backtrack(vector<int>& count, int tmp, int start) {
        if(start == count.size()) {
            if(path == tmp) sum ++;
            return;
        }

        for(int i = 0; i <= 9; i ++) {
            int temp = path;
            path = (path + i * digits[count[start]]) % 11;
            backtrack(count, tmp, start + 1);
            path = temp;
        }
    }

    vector<int> reAns(int t, vector<string>& idnums) {
        vector<int> ans(t,0);

        vector<int> yushu(t);
        for(int k = 0; k < t; k ++) {
            for(int i = 0; i < lastNums.size(); i ++) {
                if(lastNums[i] == idnums[k][17]) {
                    yushu[k] = i;
                    break;
                }
            }
        }

        for(int k = 0; k < t; k ++) {
            int tmp = 0; // 记录余数值
            vector<int> count; // 记录*号位置
            for(int i = 0; i < 17; i ++) {
                if(idnums[k][i] != '*') {
                    int num = idnums[k][i] - '0';
                    tmp = (tmp + num * digits[i]) % 11;
                }
                else if(idnums[k][i] == '*') count.push_back(i);
            }

            tmp = (yushu[k] - tmp + 11 ) % 11;
            path = 0;
            sum = 0;
            backtrack(count, tmp, 0);
            ans[k] = sum;
        }

        return ans;
    }
};

int main(void) {
    int t;
    cin >> t;
    vector<string> idnums(t);
    for(int i = 0; i < t; i ++) cin >> idnums[i];

    Solution solution;
    vector<int> ans = solution.reAns(t, idnums);
    for(int i = 0; i < t; i ++) cout << ans[i] << endl;

    return 0;
}