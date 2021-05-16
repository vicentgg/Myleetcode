#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public: 
    int rows;
    int cols;
    int count = 0;
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int k) {
        if(i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[k]) return false;
        if(k == word.size() - 1) {
            count ++;
            return true;
        }
        board[i][j] = '\0';  //字符置为空
        bool res = backtrack(board, word, i -1, j, k + 1) || backtrack(board, word, i, j - 1, k + 1)
                || backtrack(board, word, i + 1, j, k + 1) || backtrack(board, word, i, j + 1, k + 1);
        board[i][j] = word[k];

        return res;
    }

    int exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                backtrack(board, word, i, j, 0);
            }
        }

        return count;
    }
};

int main(void) {
    int m, n;
    cin >> m;
    cin >> n;
    vector<vector<char>> board(m, vector<char>(n, '\0'));

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    Solution solution;
    
    int res = solution.exist(board, word);

    cout << res << endl;

    return 0;
}