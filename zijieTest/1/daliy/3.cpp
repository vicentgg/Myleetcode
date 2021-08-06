#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minNum = 2000;

    void dfs(vector<vector<int>> &vis, vector<vector<char>> &maps, int n, int m, int i, int j, int target) {
        if(i == n - 1 && j == m - 1) minNum = min(minNum, target);
        if(i == n || i < 0 || j == m || j < 0 || vis[i][j] == 1) return;
        
        if(maps[i][j] == '#') target += 1;
        vis[i][j] = 1;
        dfs(vis,maps,n,m,i-1,j,target);
        dfs(vis,maps,n,m,i,j-1,target);
        dfs(vis,maps,n,m,i+1,j,target);
        dfs(vis,maps,n,m,i,j+1,target);
        vis[i][j] = 0;
    }

    int reAns(int n, int m, vector<vector<char>> maps) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(vis, maps, n, m, 0, 0, 0);

        return minNum;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maps(n, vector<char>(m));

    for(int i = 0; i < n; i ++) 
        for(int j = 0; j < m; j ++) 
            cin >> maps[i][j];
    
    Solution solution;
    
    cout << solution.reAns(n, m, maps);

    return 0;
}