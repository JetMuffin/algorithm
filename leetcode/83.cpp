#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        ListNode *pre = NULL;
        while(p != NULL) {
        	while(pre != NULL && p != NULL && p->val == pre->val) {
        		pre->next = p->next;
        		p = p->next;
        	}
        	if(p == NULL) break;
            pre = p;
            p = p->next;
        }
        return head;
    }
};
int main() {
	int n, t;
	Solution s;
	while(~scanf("%d", &n)) {
		scanf("%d", &t);
		ListNode* head;
	 	head = new ListNode(t);
		ListNode* p = head;
		for(int i = 0 ; i < n - 1; i++) {
			scanf("%d", &t);
			p->next = new ListNode(t);
			p = p->next;
		}
		head = s.deleteDuplicates(head);
		p = head;
		while(p != NULL) {
			cout<<p->val<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}