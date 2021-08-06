#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int reNum(int x, vector<pair<int,int>> num) {
        for(auto tp : num) {
            if(tp.first == x) x = tp.second;
            else if(tp.second == x) x = tp.first;
        }

        return x;
    }
};

int main(void) {
    int n, x, k;
    cin >> n >> x >> k;

    vector<pair<int,int>> num;
    pair<int,int> temp;
    for(int i = 0; i < k; i ++) {
        cin >> temp.first >> temp.second;
        num.push_back(temp);
    }

    Solution solution;
    cout << solution.reNum(x,num);

    return 0;
}