#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        TreeNode *p = root;
        if(root == NULL) {
        	return 0;
        }
        if(p->left != NULL & p->right != NULL) {
        	return max(maxDepth(p->left)+1, maxDepth(p->right)+1);
        } else if(p->right != NULL) {
        	return maxDepth(p->right) + 1;
        } else if(p->left != NULL) {
        	return maxDepth(p->left) + 1;
        } else {
        	return 1;
        }
    }
};
int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	Solution s;
	cout<<s.maxDepth(root)<<endl;
}