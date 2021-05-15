#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //传统方法  反转链表  双指针法
    vector<int> reversePrint(ListNode* head) {
        ListNode* prev = nullptr; //上一个节点
        
        while(head != nullptr) {
            ListNode* temp = head ->next; //下一个节点
            head ->next = prev;  //指向上一个节点
            prev = head;  //更新到下一个节点
            head = temp;
        }

        //现在prev为头节点指针

        vector<int> nums;
        while(prev) {
            nums.push_back(prev ->val);
            prev = prev ->next;
        }

        return nums;
    }
};

int main(void) {

}