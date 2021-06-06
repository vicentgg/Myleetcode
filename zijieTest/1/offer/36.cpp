#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//将一棵二叉搜索树就地转换为一个顺序双向循环链表
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
    Node(int _val, Node* _left, Node* _right) : val(_val), left(_left), right(_right) {}
};

class Solution {
public:
    Node* pre = nullptr; //当前节点前节点
    Node* head = nullptr; //循环双链表的头节点

    //中序遍历二叉树
    void dfsBuildList(Node* cur) {
        if(cur == nullptr) return;
        dfsBuildList(cur ->left);//找到当前子树的最左节点

        if(pre == nullptr) head = cur; //前节点为空的时候 当前节点为头节点
        else pre ->right = cur; //前节点不为空时  将前个节点的右节点指向当前节点
        cur ->left = pre;//当前节点的左节点 指向前个节点
        pre = cur; //更新到当前节点

        dfsBuildList(cur ->right); //遍历右子树
    }

    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return head;
        dfsBuildList(root);

        head ->left = pre;
        pre ->right = head;

        return head;
    }
};

int main(void) {

}