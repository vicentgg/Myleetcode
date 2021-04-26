#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int ans = 0;
public:
    int count(vector<vector<int>>& nums, int x1, int x2, int y1, int y2) {
        
        return ans;
    }
};

int main(void) {
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> nums(n);
    for(int i = 0; i < n; i ++) {
        nums[i].resize(m);
    }

    int x1,x2,y1,y2;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    for(int i = 0; i < n; i ++) {
        for(int j =0; j < m; j ++) {
            int num;
            cin >> num;
            nums[i][j] = num;
        }
    }

    Solution s;
    int ans = s.count(nums, x1, x2, y1, y2);
    ans = abs(x1-x2) + abs(y1-y2);
    cout << ans;

    return 0;
}