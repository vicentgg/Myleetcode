#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    unordered_map<int, int> index; //用于记录中序遍历每个值的位置

    //递归写法
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int inorder_start, int inorder_end) {
    
        int tmp = index[preorder[pre_start]]; //找到根节点在中序遍历的位置
        //左子树节点个数
        int leftNodeNum = tmp - inorder_start;

        TreeNode* root = new TreeNode(preorder[pre_start]);

        if(inorder_start <= tmp - 1) root ->left =  dfs(preorder, inorder, pre_start + 1, pre_start + leftNodeNum, inorder_start, tmp - 1);
        if(inorder_end >= tmp + 1) root ->right = dfs(preorder, inorder, pre_start + leftNodeNum + 1, pre_end, tmp + 1, inorder_end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         TreeNode* root = NULL;
         int len = inorder.size();
         if(len == 0) return NULL;

         for(int i = 0; i < len; i ++) {
             index[inorder[i]] = i;  //
         }

         root = dfs(preorder, inorder, 0, len - 1, 0, len - 1);

         return root;
    }
}; 