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
    vector<int> ans;
    void dfs(TreeNode* root, int height) {
        if(ans.size() < height + 1) {
            ans.push_back(root->val);
        } else {
            ans[height] = max(ans[height], root->val);
        }
        if(root->left != NULL) {
            dfs(root->left, height+1);
        }
        if(root->right != NULL) {
            dfs(root->right, height+1);
        }
    };
    vector<int> largestValues(TreeNode* root) {
        if(root != NULL) {
            dfs(root, 0);
        }
        return ans;
    }
};