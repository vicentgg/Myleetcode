#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


//还是使用快慢指针
class Solution {
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == nullptr) return head;
        
        ListNode* low = head;
        ListNode* fast = head;

        while(k > 1) {
            fast = fast ->next;
            -- k;
        }

        while (fast ->next)
        {
            low = low ->next;
            fast = fast ->next;
        }
        
        return low;
    }

    //反转链表 还是双指针法
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* pos = head;

        while(pos) {
            ListNode* temp = pos ->next;
            pos ->next = pre;
            pre = pos;
            pos = temp;
        }

        return pre;
    }

    //合并两个排序的链表  还是快慢指针
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //建立一个伪头节点
        ListNode* dom = new ListNode(0);
        ListNode* cur = dom;

        while (l1 && l2)
        {
            if(l1 ->val < l2 ->val) {
                cur ->next = l1;
                l1 = l1 ->next;
            }
            else {
                cur ->next = l2;
                l2 = l2 ->next;
            }
            cur = cur ->next;
        }

        cur ->next = (l1 != nullptr ? l1 : l2);

        return dom ->next;
    };

};


int main(void) {

}