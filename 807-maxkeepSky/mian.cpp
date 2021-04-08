#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int len = grid.size();
        vector<int> rol(len);
        vector<int> col(len);

        for(int i = 0; i < len; i ++) {
            for(int j = 0; j < len; j ++) {
                rol[i] = max(rol[i],grid[i][j]);
                col[j] = max(col[j],grid[i][j]);
            }
        }

        int ans = 0;
        for(int i = 0; i < len; i ++) {
            for(int j = 0; j < len; j ++) {
                ans += min(rol[i],col[j]) - grid[i][j];
            }
        }

        return ans;

    }
};

int main(void) {

}