#include<iostream>
#include<vector>
#include<stack>

//二叉树的中序遍历

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> ans;
    TreeNode *predecessor = nullptr;
public:
    vector<int> inorderTraversal(TreeNode* root) {

        //递归算法
        if(root == NULL) return ans;

        if(root->left)inorderTraversal(root->left);
        ans.push_back(root->val);
        if(root->right)inorderTraversal(root->right);

        return ans;

        //迭代算法
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()) {
            while(root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            ans.push_back(root->val);
            stk.pop();
            root = root->right;
        }

        //morris中序遍历
        while(root != nullptr) {
            if(root->left != nullptr) {
                predecessor = root->left;
                //找到root的左子树 最右的节点
                while(predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if(predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                else {
                    ans.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                    
                }
            }
            else {
                ans.push_back(root->val);
                root = root->right;
            }
        }

        return ans;
    }
};

int main(void) {

}