/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
    public:
    bool isValidBST(TreeNode* root) {
            if (root == NULL) return true;
            return isValidBST(root, LONG_MIN, LONG_MAX);
        }
    bool isValidBST(TreeNode* root, long l, long h) {
            if(root == NULL) return true;
            if(root->val <= l || root->val >= h) return false;
            return isValidBST(root->left, l, root->val) && isValidBST(root->right, root->val, h);
        }
};
