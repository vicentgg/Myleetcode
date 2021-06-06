#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    //dfs时间超了
    vector<int> path;
    int max;
    void backtrack(vector<vector<int>>& grid, int row, int col, int sum) {
        if(path.size() == grid.size() + grid[0].size() - 1) {
            if(sum > max) max = sum;
            return;
        }    
        if(row + 1 < grid.size()) {
            path.push_back(grid[row+1][col]);
            backtrack(grid, row+1, col, sum+grid[row+1][col]);
            path.pop_back();
        }
        if(col + 1 < grid[0].size()) {
            path.push_back(grid[row][col+1]);
            backtrack(grid, row, col+1, sum+grid[row][col+1]);
            path.pop_back();
        }
    }

    int maxValue(vector<vector<int>>& grid) {
        max = 0;
        int sum = grid[0][0];
        path.push_back(grid[0][0]);
        backtrack(grid,0,0,sum);
        return max;
    }

    //动态规划
    int maxValue1(vector<vector<int>>& grid) {
        //每个格子的最大值 都为左边和上边中的最大值 加上格子本身
        //先对第一行和第一列进行调整
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 1; i < row; i ++) grid[i][0] += grid[i-1][0];
        for(int j = 1; j < col; j ++) grid[0][j] += grid[0][j-1];
        for(int i = 1; i < row; i ++) {
            for(int j = 1; j < col; j ++) {
                grid[i][j] += grid[i-1][j] > grid[i][j-1] ? grid[i-1][j] : grid[i][j-1];
            }
        }

        return grid[row-1][col-1];
    }
};

int main(void) {

}