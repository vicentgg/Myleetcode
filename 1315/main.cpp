#include<iostream>
#include<vector>

using namespace std;

/*

给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：

该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
如果不存在祖父节点值为偶数的节点，那么返回 0 。


*/


struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
private:
    int ans = 0;
public:


    //该方法并未使用到gandparent, parent  还有改进的空间
     void dfs(TreeNode* gandparent, TreeNode* parent, TreeNode* node) {
        if(!node) return;
        if(gandparent->val % 2 == 0) {
            ans += node ->val;
        }
        
        dfs(parent, node, node -> left);
        dfs(parent, node, node -> right);
    }

    //改进的方法
    void ddfs(int g_val, int p_val, TreeNode* node) {
        if(!node) return;
        if(g_val % 2 == 0){
            ans += node->val;
        }
        ddfs(p_val, node->val, node->left);
        ddfs(p_val, node->val, node->right);
    }

    int sumEvenGrandparent(TreeNode* root) {

        ddfs(1,1,root);

        if(root -> left){
            dfs(root, root ->left, root ->left ->left);
            dfs(root, root ->left, root ->left ->right);
        }
        if(root -> right){
            dfs(root, root ->right, root ->right ->left);
            dfs(root, root ->right, root ->right ->right);
        }


        return ans;
    }

   
};

int main(void) {


}