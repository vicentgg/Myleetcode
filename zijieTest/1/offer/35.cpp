#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}

};

class Solution {
public:

    //复制一个单链表
    Node* copyList(Node* head) {
        Node* cur = head;
        Node* dom = new Node(0); //建立伪头节点
        Node* pre = dom;

        while(cur!=nullptr) {
            Node* node = new Node(cur ->val);
            pre ->next = node;
            cur = cur ->next;
            pre = node;
        }
        return dom ->next;
    }

    //复制一个复杂链表

    //1.使用哈希表
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        //先用一个哈希表记录每个新建节点的位置
        Node* cur = head;
        unordered_map<Node*, Node*> ListMap;
        while(cur != nullptr) {
            ListMap[cur] = new Node(cur ->val); //创建一个无指针的新节点 key为旧链表的定位指针
            cur = cur ->next;
        }

        //创建完所有新节点之后  开始连接指针
        cur = head;
        while (cur != nullptr)
        {
            ListMap[cur] ->next = ListMap[cur->next];
            ListMap[cur] ->random = ListMap[cur->random];
            cur = cur ->next;
        }
        
        return ListMap[head];
    }

    //2.在原链表上进行改动
    Node* copyRandomList1(Node* head) {
        if(head == nullptr) return head;
        Node* cur = head;

        while (cur != nullptr)
        {
            Node* tmp = new Node(cur ->val); //建立新节点 插入到原节点后面
            tmp ->next = cur ->next;
            cur ->next = tmp;
            cur = cur ->next ->next;
        }
        
        cur = head;
        while (cur != nullptr)
        {
            if(cur ->random) {
                cur ->next ->random = cur ->random ->next; //将新节点的random指针 连接到正确节点
            }
            cur = cur ->next ->next;
        }
        
        //拆分两个链表
        Node* pre = head;
        Node* ans = head ->next;
        cur = pre ->next;
        while (cur ->next != nullptr)
        {
            pre ->next = pre ->next ->next;
            cur ->next = cur ->next ->next;
            pre = pre ->next;
            cur = cur ->next;
        }
        pre ->next = nullptr;
        return ans;
        
    }

};

