#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//实现两个函数 分别用于序列化和反序列化二叉树

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Codec {
public:
    //序列化二叉树
    string serialize(TreeNode* root) {
        if(root == nullptr) return "[]";
        string ans = "[";
        queue<TreeNode*> sq;
        sq.push(root);
        TreeNode* temp = new TreeNode(0);
        while(!sq.empty()) {
            temp = sq.front();
            sq.pop();
            if(temp) {
                ans.append(to_string(temp ->val));
                sq.push(temp ->left);
                sq.push(temp ->right);
            }
            else ans.append("null");
            ans.append(",");
        }
        ans.append("]");

        return ans;
    }

    TreeNode* deserialize(string data) {
        replace(data.begin(), data.end(), ',', ' ');
        data.erase(data.begin());
        data.erase(--data.end());
        if(data.empty()) return nullptr;

        vector<TreeNode*> ans;
        string val;
        istringstream input(data); //istringstream的作用是从string对象中只读取字符
        while (input >> val)
        {
            if(val == "null") ans.push_back(nullptr);
            else ans.push_back(new TreeNode(stoi(val)));
        }
        int pos = 1;
        for(int i = 0; i < ans.size(); i ++) {
            if(ans[i] == nullptr) continue;
            ans[i] ->left = ans[pos ++];
            ans[i] ->right = ans[pos ++];
        }

        return ans[0];
    }
};
