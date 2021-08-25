#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

class Solution {
public:
    float reAns(int m, int n, int l, vector<int>& loc, vector<int>& spd) {
        float ans = 0;
        vector<float> time(n);

        if(l >= m/2 || n == 1) return ans;

        int reverse = (loc[0] + m/2) % m;
        for(int i = 1; i < n; i ++) {
            if((loc[i] - loc[0] + m) % m <= l || (loc[0] + m - loc[i]) % m <= l || (loc[i] - reverse + m) % m <= l || (reverse + m - loc[i]) % m <= l) {
                time[i] = 0;
            }
            else {
                if(spd[0] > spd[i]) {
                    int len1 = (loc[i] - loc[0] + m) % m - l;
                    int len2 = (loc[i] - reverse  + m) % m - l;
                    int len = min(len1, len2);

                    time[i] = len * 1.00 / (spd[0] - spd[i]) * 1.00;
                }
                else {
                    int len1 = (loc[0] - loc[i] + m) % m - l;
                    int len2 = (reverse - loc[i]  + m) % m - l;
                    int len = min(len1, len2);
                    time[i] = len * 1.00 / (spd[i] - spd[0]) * 1.00;
                }
            }

            ans = ans > time[i] ? ans : time[i];
        }
        return ans;
    }
};

int main(void) {
    int m, n, l;
    cin >> m >> n >> l;

    vector<int> loc(n);
    for(int i = 0; i < n; i ++) cin >> loc[i];

    vector<int> spd(n);
    for(int i = 0; i < n; i ++) cin >> spd[i];

    Solution solution;
    printf("%.2f", solution.reAns(m, n, l, loc, spd));
    
    return 0;
}