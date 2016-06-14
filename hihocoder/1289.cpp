#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
#define LL long long
char buf[50];
char op[10];
int n, m;
struct Trie {
	int index;
	Trie *next[2];
	Trie() {
		index = 0;
		for(int i = 0; i < 2; i++) {
			next[i] = NULL;
		}
	}
};

void insert(Trie *root, int ip, int mask, int index) {
	Trie *p = root;
	for(int i = 0; i < mask; i++) {
		if(p->index) {
			return; //若前面已经有rule访问该节点
		}
		int bit = (ip >> (31 - i)) & 1;
		if(p->next[bit] == NULL) {
			p->next[bit] = new Trie;
		} 
		p = p->next[bit];

	}
	if(!p->index) {
		p->index = index; //若前面已经有rule访问该节点
	}
}

int search(Trie *root, int ip) {
	Trie *p = root;
	int index = 1;
	for(int i = 0; i < 32; i++) {
		if(p->index) {
			index = p->index;
		}
		int bit = (ip >> (31-i)) & 1;
		if(p->next[bit] == NULL)
			break;
		p = p->next[bit];
	}
	return index;
}

int main() {
	int a, b, c, d;
	while(~scanf("%d%d", &n, &m)) {
        Trie *root = new Trie;
		for(int i = 1; i <= n; i++) {
			int len, k, mask = -1;
			scanf("%s%s", op, buf);
			len = strlen(buf);
			for(int j = 0; j < len; j++) {
				if(buf[j] == '/') {
					sscanf(buf+j+1, "%d", &mask);
					buf[j] = '\0';
				}
			}
			sscanf(buf, "%d.%d.%d.%d", &a, &b, &c, &d);
			k = (a<<24) + (b<<16) + (c<<8) + d;	
			if(mask == -1) {
				mask = 32;
			}		
			if(strcmp(op, "allow") == 0) {
				insert(root, k, mask, i);
			} else {
				insert(root, k, mask, -i);
			}
		}

		for(int i = 0; i < m; i++) {
			scanf("%d.%d.%d.%d", &a, &b, &c, &d);
			int k = (a<<24) + (b<<16) + (c<<8) + d;
			// cout<<search(root, k)<<endl;
			printf("%s\n", search(root, k) < 0 ? "NO" : "YES");
		}
	}
}