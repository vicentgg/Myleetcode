#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int reNum(int sum, int p, vector<pair<int,int>>& zudui, int y, vector<int>& alone) {
        int max_num = sum + p;
        int min_num = sum - p;

        int ans = 0;
        for(auto temp : zudui) {
            int t_sum = temp.first + temp.second;
            if(t_sum <= max_num && t_sum >= min_num) ans ++;
        }


        sort(alone.begin(), alone.end());

        for(int i = 0; i < y - 1; i ++) {
            if(alone[i] > max_num) break;
            for(int j = i + 1; j < y; j ++) {
                if(alone[i] + alone[j] > max_num) break;
                else if(alone[i] + alone[j] >= min_num) ans ++;
            }
        }

        return ans;

    }
};

int main(void) {
    int q1, q2, p, x;
    cin >> q1 >> q2 >> p;
    cin >> x;

    vector<pair<int,int>> zudui(x);
    for(int i = 0; i < x; i ++) cin >> zudui[i].first >> zudui[i].second;
    
    int y;
    cin >> y;
    
    vector<int> alone(y);
    for(int i = 0; i < y; i ++) cin >> alone[i];

    int sum = q1 + q2;
    Solution solution;
    cout << solution.reNum(sum, p, zudui, y, alone);

    return 0;
}
