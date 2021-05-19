#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<int> res;

    void backtrack(string& path, int n, int pos) {
        if(pos == n) {
            //将字符串除去前面多余的0  并转为整型  加入res
            res.push_back(stoi(path));
            return;
        }
        
        for(int i = 0; i <= 9; i ++) {
            path[pos] = i + '0';
            backtrack(path, n, pos + 1);
        }
    }

    vector<int> printNumbers(int n) {
        if(n <= 0) return res;
        string path(n, '0');
        backtrack(path, n, 0);

        res.erase(res.begin());
        return res;

    }
};

int main(void) {

}