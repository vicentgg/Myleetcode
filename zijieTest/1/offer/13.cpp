#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    int res = 0;
    //返回位数之和
    int getNum(int num) {
        int count = 0;
        if(num < 10) return num;
        else {
            while (num)
            {
                count += num%10;
                num /= 10;
            }
            return count;
        }
    }
    
    //深度搜索
    void dfs(vector<vector<bool>>& visited,int m, int n, int i, int j, int k) {
        
        if(i >= m || j >= n || getNum(i) + getNum(j) > k) return;

        if(visited[i][j] == false) {
            visited[i][j] = true;
            res ++;
            dfs(visited, m, n, i+1, j, k);
            dfs(visited, m, n, i, j+1, k);
        }

    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false)); //建立访问记录二维数组

        dfs(visited, m, n, 0, 0, k);

        return res;
    }
};

int main(void) {

    int m,n,k;

    cin >> m;
    cin >> n;
    cin >> k;


    Solution solution;

    cout << solution.movingCount(m,n,k);

    return 0;
}