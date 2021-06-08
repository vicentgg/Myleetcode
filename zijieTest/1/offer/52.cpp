#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        //浪漫相遇
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b)
        {
            if(a) a = a ->next;
            else a = headB;
            if(b) b = b ->next;
            else b = headA;
        }
        return a;
    }
};

int main(void) {

}