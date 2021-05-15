#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //在递增的二维数组中进行查找
    // 从左下角开始遍历查找  如果target大于当前的数  便向右移动一位  相反便向上移动一位
    //1.深度搜索
    bool dfs(vector<vector<int>>& matrix, int i, int j, int target) {
        bool res;
        if( i < 0 || j > matrix[0].size() - 1) {
            res = false;
        }
        else {
            if(matrix[i][j] == target) {
                res = true;
            }
            else if(matrix[i][j] < target) res = dfs(matrix, i, j + 1, target);
            else res = dfs(matrix, i - 1, j , target);
        }
        return res;
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        if(matrix[0].size() == 0) return false;
    
        //2.遍历
        for(int i = matrix.size() - 1, j = 0; i >= 0 && j < matrix[0].size();) {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) j += 1;
            else i -= 1;
        }
        return false;
    }
};

int main(void) {

}