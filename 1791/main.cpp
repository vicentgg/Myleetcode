#include<iostream>
#include<vector>

using namespace std;

/*

有一个无向的 星型 图，由 n 个编号从 1 到 n 的节点组成。星型图有一个 中心 节点，并且恰有 n - 1 条边将中心节点与其他每个节点连接起来。

给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示在节点 ui 和 vi 之间存在一条边。请你找出并返回 edges 所表示星型图的中心节点。

*/


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int center;
        for(int i = 0; i < 2; i ++) {
            for(int j = 0; j < 2; j ++) {
                if(edges[0][i] == edges[1][j]) center = edges[0][i];
            }
        }
        return center;
    }
};

int main(void) {

}