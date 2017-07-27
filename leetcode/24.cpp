#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL) {
    		return NULL;
    	} else if(head->next == NULL) {
    		return head;
    	}
	    ListNode* right = head->next;
	    ListNode* left = head;
	    ListNode* pre = NULL;

	    head = right;
	    while(1) {
	        left->next = right->next;
	        right->next = left;
	        if(pre != NULL)
		        pre->next = right;
	        
	        if(left->next == NULL || left->next->next == NULL) break;
	        pre = left;
	        right = left->next->next;
	        left = left->next;
	    }
	    
	    return head;
    }
};

int main() {
	int n, t;
	Solution s;
	while(scanf("%d", &n)) {
		vector<int> in;
		for(int i = 0; i < n; i ++) {
			scanf("%d", &t);
			in.push_back(t);
		}

		ListNode *head = new ListNode(in[0]);
		ListNode *p = head;
		for(int i = 1; i < in.size(); i++) {
			p->next = new ListNode(in[i]);
			p = p->next;
		}

		p = head;
		p = s.swapPairs(p);
		while(p != NULL) {
			printf("%d ", p->val);
			p = p->next;
		}		
		printf("\n");
	}
}