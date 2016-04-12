#include <iostream>
using namespace std;

struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode() {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode* node, int x) {
	if(x > node->val) {
		if(node->right != NULL) {
			insert(node->right, x);
		}else {
			node->right = new TreeNode(x);	
		}
	} else {
		if(node->left != NULL) {
			insert(node->left, x);
		}else {
			node->left = new TreeNode(x);			
		}
	}
}

void output(TreeNode* node) {
	if(node->left != NULL) {
		output(node->left);
	}
	cout<<node->val<<" ";
	if(node->right!=NULL) {
		output(node->right);
	}
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	dfs(root);
    	return root;
    }

    void dfs(TreeNode* node) {
    	if(node == NULL) return;
    	TreeNode *temp;
    	temp = node->left;
    	node->left = node->right;
    	node->right = temp;
    	cout<<node->val<<endl;
    	if(node->left != NULL) {
    		dfs(node->left);
    	}
    	if(node->right != NULL) {
    		dfs(node->right);
    	}
    }
};

int main() {
	int n, t;
	cin>>n;
	cin>>t;
	TreeNode* root = new TreeNode(t);
	for(int i = 0; i < n-1; i++) {
		cin>> t;
		insert(root, t);
	}
	output(root);
	cout<<endl;
	Solution test;
	root = test.invertTree(root);
	cout<<"!"<<endl;
	output(root);
	cout<<endl;
}