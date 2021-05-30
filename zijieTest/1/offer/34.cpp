#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//自己的写法  dfs
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(TreeNode* root, int target) {
        if(target == root ->val && root ->left == nullptr && root ->right == nullptr) {
            ans.push_back(path);
            return;
        }
        if(root ->left) {
            path.push_back(root ->left ->val);
            backtrack(root ->left, target - root ->val);
            path.pop_back();
        }
        if(root ->right) {
            path.push_back(root ->right ->val);
            backtrack(root ->right, target - root ->val);
            path.pop_back();
        }        
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        path.push_back(root ->val);
        backtrack(root, target);
        return ans;
    }
};

//改进的写法 dfs
class Solution1 {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(TreeNode* root, int target) {
        if(root == nullptr) return;
        path.push_back(root ->val);
        target -= root ->val;

        if(root ->left == nullptr && root ->right == nullptr && target == 0) {
            ans.push_back(path);
        }
        backtrack(root ->left, target);
        backtrack(root ->right, target);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        backtrack(root, target);
        return ans;
    }
};