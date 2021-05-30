//针对无序链表 进行排序 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    //最优的选择 归并排序 时间复杂度为O(nlogn) 空间复杂度也从顺序表的O(n) 降为了常量
    //归并排序
    //1.找到中间 并递归
    ListNode* MergeSort(ListNode* head) {
        //使用快慢双指针 找到中间节点
        ListNode* fast = head;
        ListNode* low = head;
        if(fast == nullptr || fast ->next == nullptr) return fast;
        while(fast ->next && fast ->next ->next) {
            fast = fast ->next ->next;
            low = low ->next;
        }
        fast = low;
        low = low ->next;
        fast ->next = nullptr;
        fast = MergeSort(head);
        low = MergeSort(low);
        return MergeList(fast, low);
    }
    //2.合并两个有序链表
    ListNode* MergeList(ListNode* l1, ListNode* l2) {
        ListNode* dom = new ListNode(0); // 新建一个伪头节点
        ListNode* cur = dom;

        while(l1 && l2) {
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
    }

    //直接插入排序 O(n*n)
    ListNode* InsertSort(ListNode* head) {
        if(head == nullptr || head ->next == nullptr) return head;
        ListNode* dom = new ListNode(0);  //建立一个伪头节点
        dom ->next = head;
        ListNode* start = dom;
        ListNode* pre = head;
        ListNode* p;
        while(pre ->next != nullptr) {
            p = pre ->next;
            if(p ->val < pre ->val) {
                pre ->next = p ->next;
                while(start ->next ->val <= p ->val) {
                    start = start ->next;
                }
                p ->next = start ->next;
                start ->next = p;
                start = dom;
            }
            else {
                pre = pre ->next;
            }
        }

        return start ->next;
    }

    //冒泡排序
    ListNode* bubbleSort(ListNode* head) {
        if(head == nullptr || head ->next == nullptr) return head;
        ListNode* p = head; 
        ListNode* q = nullptr; //记录已排好的链表位置

        bool flag;
        while(q != head ->next) {
            flag = false;
            p = head;
            while(p ->next != q) {
                if(p ->next ->val < p ->val) {
                    swap(p ->next ->val, p ->val);
                    flag = true;
                }
                p = p ->next;
            }

            if(flag == false) break;
            q = p;
        }

        return head;
    }
};

int main(void) {
    int n;
    cin >> n;
    ListNode* head = new ListNode(0);
    ListNode* p = head;

    while(n --){
        int val;
        cin >> val;

        ListNode* temp = new ListNode(val);

        p ->next = temp;
        p = p ->next;
    }

    Solution solution;
    ListNode* ans = solution.bubbleSort(head ->next);
    while(ans) {
        cout << ans->val << " ";
        ans = ans ->next;
    }

    return 0;
}