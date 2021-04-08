#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        //前序递归遍历
        if(original == NULL)return NULL;

        if(original == target)return cloned;

        TreeNode* res = getTargetCopy(original->left, cloned->left, target);
        if(res != NULL) return res;

        res = getTargetCopy(original->right,cloned->right,target);
        if(res != NULL) return res;

        return NULL;

        //前序非递归遍历
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        while(original != NULL || !s1.empty()) {

            if(original != NULL) {
                if(original == target) {
                    return cloned;
                }

                s1.push(original);
                original = original->left;
                s2.push(cloned);
                cloned = cloned->left;
            }
            else {
                original = s1.top();
                s1.pop();
                original = original->right;

                cloned = s2.top();
                s2.pop();
                cloned = cloned->right;
            }   
        }

        return NULL;
    }
};

int main(void) {

}