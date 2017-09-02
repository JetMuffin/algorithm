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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode *l = root, *r = root;
        int dl = 0, dr = 0;
        while(l) {
            dl++;
            l = l->left;
        }
        while(r) {
            dr++;
            r = r->right;
        }
        if(dl == dr) return (1 << dl) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
