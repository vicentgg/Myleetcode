#include<vector>
#include<iostream>
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
    //26 在A中找到B
    //同时先序遍两棵树 如果B遍历完 就是相同  
    bool dfs(TreeNode* A, TreeNode* B) {
        if(B == nullptr) return true;
        if(A == nullptr || A ->val != B ->val) return false;

        return dfs(A ->left, B ->left) && dfs(A ->right, B ->right);
       
    }
    
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr) return false;

        bool res = false;

        if(A ->val == B ->val) {
            res = dfs(A, B);
        }
        
        //当前节点不满足 遍历孩子节点
        if(res == false) {
            res = isSubStructure(A ->left, B) || isSubStructure(A ->right, B);
        }

        return res;
    }

    //27 二叉树的镜像
    //1.递归方法
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* temp = root ->left;
        root ->left = mirrorTree(root ->right);
        root ->right = mirrorTree(temp);

        return root;
    }
    //2.使用栈

    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return root;
        stack<TreeNode*> sTree;
        TreeNode* start = root;
        

        //找到最左子树 遍历栈 开始依次交换左右子树
        while(!sTree.empty() || start != nullptr) {

            while(start != nullptr) {
                sTree.push(start);
                start = start ->left;
            }

            TreeNode* temp = sTree.top();
            sTree.pop();
            
            start = temp ->right;

            //交换左右子树
            TreeNode* t = temp ->left;
            temp ->left = temp ->right;
            temp ->right = t;
        }

        return root;
    }




    //28.对称的二叉树

    //递归方式实现
    bool dfs(TreeNode* left, TreeNode* right) {
        if(!left || !right) return !left && !right; //都不存在时返回true 只有一方存在时 返回false
        if(left ->val != right ->val) return false;

        return dfs(left ->left, right ->right) && dfs(left ->right, right ->left);
    }

    //迭代方式实现
    bool isSyTree(TreeNode* root) {
        queue<TreeNode*> sq;
        sq.push(root ->left);
        sq.push(root ->right);

        while(!sq.empty()) {
            TreeNode* leftNode = sq.front(); sq.pop();
            TreeNode* rightNode = sq.front(); sq.pop();

            if(!leftNode && !rightNode) continue;
            if(!leftNode || !rightNode || leftNode ->val != rightNode ->val) return false;

            sq.push(leftNode ->left);
            sq.push(rightNode ->right);
            sq.push(leftNode ->right);
            sq.push(rightNode ->left);
        }
    }


    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root ->left, root ->right);
        // return isSyTree(root);
    }




    //32-1.层序遍历二叉树
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        TreeNode* start = root;
    
        if(!start) return ans;
        q.push(start);

        while(!q.empty()) {
            ans.push_back(q.front() ->val);
            if(q.front() ->left)q.push(q.front() ->left);
            if(q.front() ->right)q.push(q.front() ->right);
            q.pop();
        }

        return ans;
    }

    //32-2 从上到下打印二叉树 
    vector<vector<int>> levelOrder1(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        TreeNode* start = root;

        if(!start) return ans;
        q.push(start);

        while (!q.empty())
        {
            vector<int> tmp;
            int len = q.size() - 1;
            for(int i = len; i >= 0; i --) {
                tmp.push_back(q.front() ->val);
                if(q.front() ->left)q.push(q.front() ->left);
                if(q.front() ->right)q.push(q.front() ->right);
                q.pop();
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }

    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        TreeNode* start = root;
        if(!start) return ans;

        q.push(start);
        int layer = 1;
        while(!q.empty()) {
            vector<int> tmp;
            int len = q.size() - 1;
            for(int i = len; i >= 0; i --) {
                if(layer % 2 == 1) tmp.push_back(q.front() ->val);
                else tmp.insert(tmp.begin(), q.front() ->val);

                if(q.front() ->left)q.push(q.front() ->left);
                if(q.front() ->right)q.push(q.front() ->right);
                q.pop();
            }
            ans.push_back(tmp);
            layer ++;
        }

        return ans;
    }
};

int main(void) {

}