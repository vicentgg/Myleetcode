#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    //68-1  找到二叉搜索树的最近公共祖先 递归
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p ->val < root ->val && q ->val < root ->val) {
            return lowestCommonAncestor(root ->left, p, q);
        }
        else if(p ->val > root ->val && q ->val > root ->val) {
            return lowestCommonAncestor(root ->right, p, q);
        }
        return root;
    }
    //迭代
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //优化条件 保持q最大
        if(p ->val > q ->val) {
            TreeNode* tmp = p;
            p = q;
            q = tmp;
        }
        while (root)
        {
            if(root ->val > q ->val) {
                root = root ->left;
            }
            else if(root ->val < p ->val) {
                root = root ->right;
            }
            else break;
        }
        
        return root;
    }

    //68-2 找到二叉树中的两个指定节点的最近公共祖先
    //后序遍历二叉树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root ->left, p, q);
        TreeNode* right = lowestCommonAncestor(root ->right, p, q);
        
        if(left == nullptr) return right;
        else if(right == nullptr) return left;
        return root;
    }

};

int main(void) {

}