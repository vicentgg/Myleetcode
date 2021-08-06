#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    //54 遍历二叉搜索树 找到第k大的节点
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> sk;
        TreeNode* p = root;
        int ans;
        while(!sk.empty() || p != nullptr) {
            while(p != nullptr) {
                sk.push(p);
                p = p ->right;
            }
            if(!sk.empty()) {
                p = sk.top();
                ans = p ->val;
                if(--k == 0) break;
                sk.pop();
                p = p ->left;
            }

        }

        return ans;
    }

    //55-1 求出一个二叉树的深度 深度遍历
    //dfs
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    //bfs
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        int depth = 0;
        int size = 0;
        q.push(root);
        while(!q.empty()) {
            size = q.size();
            depth ++;
            for(int i = 0; i < size; i ++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp ->left)q.push(temp ->left);
                if(temp ->right)q.push(temp ->right);
            }
        }

        return depth;
    }

    //55-2 判断一个二叉树是不是平衡二叉树
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = dfs(root ->left);
        if(left == -1) return -1;
        int right = dfs(root ->right);
        if(right == -1) return -1;
        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) == -1 ? false : true;
    }
};

int main(void) {

}