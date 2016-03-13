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
    ListNode* oddEvenList(ListNode* head) {
    	ListNode* new_head = NULL;
    	ListNode* p = head;
    	ListNode* new_p;
    	int count = 1;
    	while(p != NULL) {
    		if(count%2 == 1) {
    			if(new_head == NULL) {
					new_head = new ListNode(p->val);
		    		new_p = new_head;
    			} else {
    				new_p->next = new ListNode(p->val);
    				new_p = new_p->next;
    			}
    		}
    		p = p->next;
    		count ++;
    	}

    	p = head;
    	count = 1;
    	while(p != NULL) {
    		if(count%2 == 0) {
				new_p->next = new ListNode(p->val);
				new_p = new_p->next;
    		}
    		p = p->next;
    		count ++;
    	}  
    	return new_head;	
    }
};

int main() {
	int n, v;
	// input
	cin>>n;
	cin>>v;
	ListNode* head = new ListNode(v);
	ListNode* p = head;
	for(int i = 1 ; i < n; i++) {
		cin>>v;
		ListNode* cur = new ListNode(v);
		p->next = cur;
		p = cur;
	}

	Solution solution;
	ListNode* new_head = solution.oddEvenList(head);

	// output
	p = new_head;
	while(p != NULL) {
		cout<< p->val << endl;
		p = p->next;
	}
	return 0;
}