#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef struct node{
	struct node* left;
	struct node* right;
	struct node* up;
	struct node* down;
	int x, y;
	void print() {
		printf("%d %d\n", x, y);
	}
}node;
vector<node*> column;
vector<node*> nodes;
node *head;
int n, m;
int board[105][105];
int id[105][105];
int ans[105];
void build() {
	head = new node;
	head->left = head->right = head->up = head->down = head;
	head->x = head->y = 0;
	column.clear();
	node *pre = head;
	for(int i = 1; i <= m; i++) {
		node *p = new node;
		p->up = p;
		p->down = p;
		p->x = 0;
		p->y = i;
		p->right = pre->right;
		pre->right = p;
		p->left = pre;
		pre = p;
		column.push_back(p);
	}
	if(column.size() > 0) {
		head->right = column[0];
	}

	int cnt = 0;
	nodes.clear();
	for(int i = 1; i <= n; i++) {
		for(int j = 1 ; j <= m; j++) {
			if(board[i][j] == 1) {
				cnt ++;
				id[i][j] = cnt;
				node *t = new node;
				t->left = t->right = t->up = t->down = t;
				t->x = i;
				t->y = j;
				nodes.push_back(t);
			}
		}
	}

	for(int j = 1 ; j <= n; j++) {
		node *pre = column[j-1];
		for(int i = 1 ; i <= m; i++) {
			if(board[i][j] == 1) {
				node* p = nodes[id[i][j]-1];
				p->down = pre->down;
				p->up = pre;
				pre->down->up = p;
				pre->down = p;
				pre = p;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		node *pre = NULL;
		for(int j = 1 ; j <= m; j++) {	
			if (board[i][j] == 1) {
				if (pre == NULL) {
					pre = nodes[id[i][j]-1];
				} else {
					node* p = nodes[id[i][j]-1];
					p->right = pre->right;
					p->left = pre;
					pre->right->left = p;
					pre->right = p;
					pre = p;
				}
			}			
		}
	}
}

void trace() {
	node *p = head;
	node *p2 = p->right;
	while(p2 != p) {
		p2->print();
		node *p3 = p2->down;
		while(p3 != p2) {
			p3->print();
			p3 = p3->down;
		}
		p2 = p2->right;
	}
}

void remove(int col) {
	// cout<<"---remove-trace:"<<col+1<<"---"<<endl;
	node *p = column[col];
	p->right->left = p->left;
	p->left->right = p->right;
	node *p2 = p->down;
	while(p2 != p) {
		// cout<<"remove:";
		// p2->print();		
		node *p3 = p2->right;
		while (p3 != p2) {
			p3->down->up = p3->up;
			p3->up->down = p3->down;
			// cout<<"remove:";
			// p3->print();		
			p3 = p3->right;
		}
		p2 = p2->down;
	}
	// trace();
}

void resume(int col) {
	// cout<<"---resume-trace:"<<col+1<<"---"<<endl;
	node *p = column[col];
	p->right->left = p;
	p->left->right = p;
	node *p2 = p->down;
	while(p2 != p) {
		node *p3 = p2->right;
		while(p3 != p2) {
			p3->down->up = p3;
			p3->up->down = p3;
			p3 = p3->right;
		}
		p2 = p2->down;
	}
	// trace();
}

void road(int depth) {
	cout<<"road:";
	for(int i = 0 ; i< depth; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
bool dance(int depth) {
	// cout<<"---trace:"<<depth<<"---"<<endl;
	// trace();
	// road(depth);
	node *p = head->right;
	if (head == p) {
		return true;
	}
	node *p2 = p->down;
	if(p2 == p) {
		return false;
	}


	// cout<<"---col-remove---"<<endl;
	// cout<<"pick:";
	// p2->print();		
	remove(p->y-1);
	while(p2 != p) {	
		ans[depth] = p2->x;
		node *p3 = p2->right;
		// cout<<"---row-col-remove---"<<endl;
		while(p3 != p2) {
			remove(p3->y-1);
			p3 = p3->right;
		}

		if(dance(depth+1)) {
			return true;
		}

		p3 = p2->left;
		while(p3 != p2) {
			resume(p3->y-1);
			p3 = p3->left;
		}

		p2 = p2->down;		
	}
	resume(p->y-1);
	return false;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1 ; i <= n; i++) {
			for(int j = 1 ; j <= m; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		build();
		if(dance(0)) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
}