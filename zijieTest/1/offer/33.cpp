#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

//判断一个数组是否为一颗二叉搜索树的后序遍历
class Solution {
public:
    vector<int> res;
    bool verifyPostorder(vector<int>& postorder) {
        res = postorder;
        return dfs(0, postorder.size() - 1);
    }

    bool dfs(int left, int right) {
        if(left >=  right) return true;
        int root = res[right];
        int k = left;
        while(k < right && res[k] < root) k ++; //找到左子树区间
        for(int i = k; i < right; i ++) {
            if(res[i] < root) return false; //遍历右子树 如果发现小于根节点 就false
        }
        return dfs(left, k - 1) && dfs(k, right - 1);
    }
};

