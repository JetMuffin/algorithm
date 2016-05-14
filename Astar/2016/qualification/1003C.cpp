#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#define MAX 26
using namespace std;

struct Trie {
	int count;
	bool isWord;
	Trie *next[26];
	Trie() {
		count = 1;
		isWord = false;
		for(int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
	}
};

void insert(Trie *root, string str) {
	Trie *p = root;
	for(int i = 0; i < str.length(); i++) {
		int num = str[i] - 'a';
		if(p->next[num] == NULL) {
			p->next[num] = new Trie;
		} else {
			p->next[num]->count++;
		}
		p = p->next[num];

	}
	p->isWord = true;
}

bool search(Trie *root, string str) {
	Trie *p = root;
	for(int i = 0; i < str.length(); i++) {
		int num = str[i] - 'a';
		if(p->next[num] == NULL) {
			return false;
		}
		p = p->next[num];
		// cout<<str[i]<<" "<<p->count<<endl;
	}
	return p->count > 0;
}

void remove(Trie *root, string str) {
	Trie *p = root;
	Trie *pre = root;
	for(int i = 0; i < str.length(); i++) {
		int num = str[i] - 'a';
		if(p->next[num] == NULL) {
			return;
		}
		pre = p;
		p = p->next[num];
	}

	int count = p->count;
	p = root;
	for(int i = 0; i < str.length(); i++) {
		int num = str[i] - 'a';
		if(p->next[num] == NULL) {
			return;
		}
		p = p->next[num];
		p->count -= count;
	}	

	int num = str[str.length()-1] - 'a';
	pre->next[num] = NULL;
}

char s[200], op[50];

int main() {
    int n;
    scanf("%d", &n);
    // while(~scanf("%d", &n)){
        Trie *root = new Trie;
        root->count = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", op);
            scanf("%s", s);
            if(strcmp(op, "insert") == 0) {
                insert(root, s);
            } else if(strcmp(op, "search") == 0){
                bool flag = search(root, s);
                if(flag) {
                    puts("Yes");
                } else {
                    puts("No");
                }
            } else if(strcmp(op, "delete") == 0){
                remove(root, s);
            }
        }
    // }	
}