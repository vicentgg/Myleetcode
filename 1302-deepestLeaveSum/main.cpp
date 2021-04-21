#include<iostream>
#include<queue>

using namespace std;

/* 
给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

using PTI = pair<TreeNode*,int>; //构建队列元素模板

class Solution {

//深度优先搜索

private:
    int maxdep = -1;
    int total = 0;

public:
    void dfs(TreeNode* node, int dep) {
        if(!node) {
            return;
        }

        if(dep == maxdep) {
            total += node ->val;
        }
        else if(dep > maxdep) {
            maxdep = dep;
            total = node ->val;
        }

        dfs(node ->left, dep + 1);
        dfs(node ->right, dep + 1);
    }

    int deepestLeaveSum(TreeNode* root) {
        // dfs(root, 0);
        // return total;

        queue<PTI> q;

        q.emplace(root, 0);

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int dep = q.front().second;
            q.pop();
            
            if(dep > maxdep) {
                maxdep = dep;
                total = node ->val;
            }
            else if(dep == maxdep) {
                total += node ->val;
            }

            if(node ->left) {
                q.emplace(node ->left, dep + 1);
            }
            if(node ->right) {
                q.emplace(node ->right, dep + 1);
            }
        }

        return total;

    }


};

int main(void) {

}