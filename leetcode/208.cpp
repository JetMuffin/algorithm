#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class Node {
public:
	int cnt;
	bool end;
	Node *child[26];
	Node() {
	    cnt = 0;
	    end = false;
        memset(child, 0, sizeof(child));
	}
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
    	root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	Node *p = root;
        for(int i = 0; i < word.size(); i++) {
        	int idx = word[i] - 'a';
        	if(p->child[idx] == NULL) {
        		p->child[idx] = new Node();
        	}
        	p = p->child[idx];
        	p->cnt++;
        }
        p->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	Node *p = root;
        for(int i = 0; i < word.size(); i++) {
        	int idx = word[i] - 'a';
        	if(p->child[idx] == NULL) {
        		return false;
        	}
        	p = p->child[idx];
        }
        return p->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
    	Node *p = root;
        for(int i = 0; i < prefix.size(); i++) {
        	int idx = prefix[i] - 'a';
        	if(p->child[idx] == NULL) {
        		return false;
        	}
        	p = p->child[idx];
        }
        return true;
    }

private:
	Node *root;
};
int main() {
	Trie *tree = new Trie();
	int n, m;
	string s;
	while(cin>>n>>m) {
		for(int i = 0; i < n; i++) {
			cin>>s;
			tree->insert(s);
		}
		for(int i = 0; i < m; i++) {
			cin>>s;
			cout<<tree->search(s)<<" "<<tree->startsWith(s)<<endl;
		}
	}
}