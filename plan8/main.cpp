#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int ans(vector<vector<int>> loads, int a, int b) {
        return 5;
    }
};

int main(void) {
    int n, m, a, b;

    vector<vector<int>> loads;

    for(int i = 0; i < m; i ++) {
        vector<int> l(3);
        cin >> l[0];
        cin >> l[1];
        cin >> l[2];

        loads.push_back(l);
    }

    Solution s;
    cout << s.ans(loads, a, b);

    return 0;
}