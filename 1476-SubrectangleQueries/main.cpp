#include<iostream>
#include<vector>

using namespace std;


/*

请你实现一个类 SubrectangleQueries ，它的构造函数的参数是一个 rows x cols 的矩形（这里用整数矩阵表示），
并支持以下两种操作：

1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

用 newValue 更新以 (row1,col1) 为左上角且以 (row2,col2) 为右下角的子矩形。

2. getValue(int row, int col)

返回矩形中坐标 (row,col) 的当前值。
*/

class SubrectangleQueries {
private:
    vector<vector<int>> rec;
    vector<vector<int>> history; //矩阵变化记录数组

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {

        // 传统暴力解法 进行真正的更新
        // for(int i = row1; i <= row2; i ++) {
        //     for(int j = col1; j <= col2; j ++) {
        //         rec[i][j] = newValue;
        //     }
        // }

        history.push_back({row1,col1,row2,col2,newValue});

    }
    
    int getValue(int row, int col) {
        
        for(int i = history.size() - 1; i >= 0; i --) {
            if(history[i][0] <= row && history[i][1] <= col && history[i][2] >= row && history[i][3] >= col) {
                return history[i][4];
            }
        }
        return rec[row][col];
    }

};
