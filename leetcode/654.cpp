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
    TreeNode * buildTree(int start, int end, vector<int>& nums) {
        int idx = start, maxx = nums[start];
        for(int i = start+1; i <= end; i++) {
            if(nums[i] > maxx) {
                maxx = nums[i];
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(maxx);
        if(start <= idx-1)
            root->left = buildTree(start, idx-1, nums);
        if(idx+1 <= end)
            root->right = buildTree(idx+1, end, nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return buildTree(0, nums.size()-1, nums);;
    }
};