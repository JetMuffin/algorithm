#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
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
class Solution {
public:
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	bool vis[1000][1000];
	Trie *tree;
	set<string> ret;
	int n, m;
	void dfs(vector<vector<char> >& board, int x, int y, string s) {
		// cout<<s<<" "<<tree->startsWith(s)<<" "<<tree->search(s)<<endl;
		if(!tree->startsWith(s)) return;
		if(tree->search(s)) {
			ret.insert(s);
		}
		for(int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 && yy >= 0 && xx < n && yy < m && !vis[xx][yy]) {
				vis[xx][yy] = true;
				dfs(board, xx, yy, s+board[xx][yy]);
				vis[xx][yy] = false;
			}
		}
	}
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        tree = new Trie();
        ret.clear();
        for(int i = 0; i < words.size(); i++) {
        	tree->insert(words[i]);
        }

        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		memset(vis, 0, sizeof(vis));
        		string s;
        		s += board[i][j];
        		vis[i][j] = true;
        		dfs(board, i, j, s);
        		vis[i][j] = false;
        	}
        }
        vector<string> ans;
        for(set<string>::iterator it = ret.begin(); it != ret.end(); it++) {
        	ans.push_back(*it);
        }
        return ans;
    }
};
int main() {
	int n, q;
	vector<vector<char> > board;
	vector<string> words;
	string s;
	Solution so;
	while(cin>>n>>q) {
		for(int i = 0; i < n; i++) {
			cin>>s;
			vector<char> v;
			board.push_back(v);
			for(int j = 0; j < s.length(); j++) {
				board[i].push_back(s[j]);
			}
		}
		for(int i = 0; i < q; i++) {
			cin>>s;
			words.push_back(s);
		}
		vector<string> ans = so.findWords(board, words);
		for(int i = 0; i < ans.size(); i++) {
			cout<<ans[i]<<endl;
		}
	}
}