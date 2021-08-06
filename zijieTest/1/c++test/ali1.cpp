#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    char reAns(vector<pair<int,int>>& num, vector<vector<int>>& ope, int t) {
        int temp = max(num[t].first, num[t].second);
        int len = ope[t].size();
        int count = 0;
        for(int i = 0; i < len; i ++) {
            if(count >= 3) return 'N';
            if(ope[t][i] == 0) continue;
            else if(ope[t][i] != temp) count ++;
            else {
                return 'Y';
            }
        }

        return 'N';
    }
};

int main(void) {
    int t;
    cin >> t;
    vector<pair<int,int>> num(t);
    vector<vector<int>> ope(t, vector<int>(30));

    for(int i = 0; i < t; i ++) {
        cin >> num[i].first >> num[i].second;
        for(int j = 0; j < 30; j ++) {
            cin >> ope[i][j];
        }
    }

    Solution solution;
    for(int i = 0; i < t; i ++) {
        cout << solution.reAns(num, ope, i) << endl;
    }

    return 0;
}