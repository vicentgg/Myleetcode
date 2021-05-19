#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//删除链表的指定节点

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr) return nullptr;

        ListNode* p = head;

        if(p ->val == val) {
            head = p ->next;
            return head;
        }

        while(p ->next) {
            if(p ->next ->val == val) {
                p -> next = p ->next ->next;
                return head;
            }
            p = p ->next;
        }
        return head;
    }
};

int main(void) {

}