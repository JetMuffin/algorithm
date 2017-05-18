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
    int ans = 99999999;
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root, 1);
        return ans;
    }
    void dfs(TreeNode* root, int cnt) {
        if(root->left == NULL && root->right == NULL) {
            ans = min(ans, cnt);
        }
        if(root->left != NULL) dfs(root->left, cnt+1);
        if(root->right != NULL) dfs(root->right, cnt+1);
    }
};
