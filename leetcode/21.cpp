#include <iostream>
#include <cstdio>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p = new ListNode(0);
        if (p1->val < p2->val) {
            p = new ListNode(p1->val);
            p1 = p1->next;
        } else {
            p = new ListNode(p2->val);
            p2 = p2->next;
        }

        ListNode *head = p;
        while(p1 != NULL &&  p2 != NULL) {
            if(p1->val < p2->val) {
                p->next = new ListNode(p1->val);
                p = p->next;
                p1 = p1->next;
            } else {
                p->next = new ListNode(p2->val);
                p = p->next;
                p2 = p2->next;
            }
            ListNode *pp = head;
        }
        while(p1 != NULL) {
            p->next = new ListNode(p1->val);
            p = p->next;
            p1 = p1->next;
        }
        while(p2 != NULL) {
            p->next = new ListNode(p2->val);
            p = p->next;
            p2 = p2->next;
        }
        return head;
    }
};
int main() {
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* p = s.mergeTwoLists(l1, l2);
    while(p != NULL) {
        printf("%d\n", p->val);
        p = p->next;
    }
}
