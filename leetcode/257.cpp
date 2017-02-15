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
    vector<string> list;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return list;
    }
    void dfs(TreeNode* root, string cur) {
        if(root == NULL) return;
        stringstream stream; 
        stream<<root->val;
        string valstr = stream.str();
        if(root->left == NULL && root->right == NULL) {
            cur = cur + valstr;
            list.push_back(cur);
            return;
        } 

        if(root->left != NULL) {
            dfs(root->left, cur + valstr + "->");
        }
        if(root->right != NULL) {
            dfs(root->right, cur + valstr + "->");
        }
    }
};