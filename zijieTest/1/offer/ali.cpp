#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* lsort(ListNode* head) {
        ListNode* q = head;
        while(q ->next) {
            ListNode* p = head;
            bool t = false;
            while (p ->next)
            {
                if(p ->next->val < p ->val) {
                    ListNode* temp = p ->next;
                    p ->next = temp ->next;
                    temp ->next = p;
                    t = true;
                }
                else {
                    p = p ->next;
                }
            }
            if(t == false) break;
            q = q ->next;
        }
    }
};

int main(void) {

}

