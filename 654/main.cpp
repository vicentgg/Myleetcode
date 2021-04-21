#include<iostream>
#include<vector>

using namespace std;

/*

给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

二叉树的根是数组 nums 中的最大元素。
左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
返回有给定数组 nums 构建的 最大二叉树 。

*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        int length = nums.size();
        if(length == 1) {
            node ->val = nums[0];
            return node;
        }

        int max = 0;
        int max_loc = 0;

        for(int i = 0; i < length; i ++) {
            if(nums[i] > max) {
                max = nums[i];
                max_loc = i;
            }
        }

        node ->val = max;
       
        if(max_loc > 0) {
            vector<int> num1(nums.begin(),nums.begin() + max_loc); // ！！！新建数组中有max_loc数
            node ->left = constructMaximumBinaryTree(num1);
        }
        if(max_loc < length - 1) {
            vector<int> num2(nums.begin() + max_loc + 1, nums.end());
            node ->right = constructMaximumBinaryTree(num2);
        }


        return node;

    }


};

int main(void) {

}