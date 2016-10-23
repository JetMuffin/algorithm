/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int ans = 0;
        if(root->left != NULL) {
            if(root->left->left == NULL && root->left->right == NULL)
                ans += root->left->val;
            ans += sumOfLeftLeaves(root->left);
        }
        if(root->right != NULL) {
            ans += sumOfLeftLeaves(root->right);
        }
        return ans;
    }
};
