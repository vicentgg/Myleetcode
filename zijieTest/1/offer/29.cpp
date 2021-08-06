#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int buttom = matrix.size() - 1;
        
        while(true) {
            for(int i = left; i <= right; i ++) ans.push_back(matrix[top][i]);
            if(++top > buttom) break;
            for(int i = top; i <= buttom; i ++) ans.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i --) ans.push_back(matrix[buttom][i]);
            if(--buttom < top) break;
            for(int i = buttom; i >= top; i --) ans.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        
        return ans;
    }
};

int main(void) {

}