#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> lists;

        if(tree == nullptr) {
            return lists;
        }

        queue<TreeNode*> q;
        q.emplace(tree);

        while(!q.empty()) {
            ListNode* head = nullptr;
            ListNode* prev = nullptr;

            int len = q.size();
            for(int i = 0; i < len; i ++) {
                TreeNode* currNode = q.front();
                ListNode* newNode = new ListNode(currNode->val);
                q.pop();

                if(head == nullptr) {
                    head = newNode;
                } else {
                    prev->next = newNode;
                }
                prev = newNode;

                if(currNode->left) {
                    q.emplace(currNode->left);
                }
                if(currNode->right) {
                    q.emplace(currNode->right);
                }
            }

            lists.emplace_back(head);
        }

        return lists;
       
    }
};

int main(void) {

}