#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;
    void dfs(vector<vector<int>>& matrix, int r1, int r2, int c1, int c2) {
        if(r1 > r2 || c1 > c2) return;
        for(int i = c1; i <= c2; i ++) path.push_back(matrix[r1][i]);
        for(int j = r1 + 1; j <= r2; j ++) path.push_back(matrix[j][c2]);
        if(r1 != r2 && c1 != c2) {
            for(int i = c2 - 1; i >= c1; i --) path.push_back(matrix[r2][i]);
            for(int j = r2 - 1; j >= r1 + 1; j --) path.push_back(matrix[j][c1]);
        }
        dfs(matrix, r1 + 1, r2 - 1, c1 + 1, c2 - 1);
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return {};
        int col = matrix[0].size();
        if(col == 0) return {};

        dfs(matrix, 0, row - 1, 0, col - 1);

        return path;
    }
};

int main(void) {

}