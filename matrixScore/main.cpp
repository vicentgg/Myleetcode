#include<iostream>
#include<vector>

using namespace std;

/*
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

返回尽可能高的分数。
*/

class Solution {
    
public:
    int matrixScore(vector<vector<int>>& A) {

        //贪心算法

        int row = A.size();
        int col = A[0].size();

        int count = row * ( 1 << (col-1)); //左移col-1位
      
        for(int j = 1; j < col; j ++) {

            int sum = 0;
            for(int i = 0; i < row; i ++) {
                if(A[i][0] == 1) {
                    sum += A[i][j];
                }
                else {
                    sum += (1 - A[i][j]);
                }
            }

            int maxS = max(sum, row - sum);
            count += maxS * ( 1 << (col - 1 -j)); 
            
        }
        return count;
    }

};

int main(void) {

}