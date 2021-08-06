#include<vector>
#include<algorithm>
#include<iostream>
#include<stack>

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

    //前序遍历非递归
    vector<int> preorder(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        if(root == nullptr) return ans;

        while(!st.empty() || root) {
            while(root) {
                ans.push_back(root ->val);
                st.push(root);
                root = root ->left;
            }

            root = st.top();
            st.pop();
            root =  root ->right;
        }

        return ans;
    }


    //中序遍历非递归
    vector<int> inorder(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        if(root == nullptr) return ans;

        while(!st.empty() || root) {
            while(root) {
                st.push(root);
                root = root ->left;
            }
            
            root = st.top();
            ans.push_back(root ->val);
            st.pop();
            root = root ->right;
        }

        return ans;
    }

    //后序遍历非递归
    vector<int> postorder(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        if(root == nullptr) return ans;

        while(cur) {
            st.push(cur);
            cur = cur ->left; //先找到最左节点
        }

        while(!st.empty()) {
            cur = st.top(); //取栈顶元素
            if(cur ->right == nullptr || cur ->right == pre) { //当该节点的右孩子不存在  或者已经被访问的时候
                ans.push_back(cur ->val); //才可以直接访问该节点 
                pre = cur; //并更新为上一个访问节点
                st.pop();  //弹栈
            }
            else {
                cur = cur ->right; //右孩子存在 且没有被访问时
                while(cur) {  //需要遍历右孩子树
                    st.push(cur);
                    cur = cur ->left;
                }
            }
        
        }

        return ans;
    }

};

int main(void) {

}