#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Node {
	int cnt;
	bool isWord;
	Node *child[26];
	Node() {
		memset(child, 0, sizeof(child));
		isWord = false;
		cnt = 0;
	}
};
void insert(Node *root, string s) {
	if(root == NULL) return;
	Node *p = root;
	for(int i = 0; i < s.length(); i++) {
		int idx = s[i] - 'a';
		if (p->child[idx] == NULL) p->child[idx] = new Node();
		p = p->child[idx];
		p->cnt++;
	}
	p->isWord = true;
}
int find(Node *root, string s) {
	if(root == NULL) return 0;
	Node *p = root;
	for(int i = 0; i < s.length(); i++) {
		int idx = s[i] - 'a';
		if (p->child[idx] ==  NULL) return 0;
		p = p->child[idx];
	}
	return p->cnt;
}
int main() {
	int n, q;
	string s;
	while(~scanf("%d", &n)) {
		Node *tree = new Node();
		for(int i = 0; i < n; i++) {
			cin>>s;
			insert(tree, s);
		}
		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			cin>>s;
			printf("%d\n", find(tree, s));
		}
	}

}