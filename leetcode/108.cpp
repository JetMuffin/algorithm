#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        TreeNode* root;
        build(0, nums.size()-1, nums, root);
        return root;
    }
    void build(int l, int r, vector<int>& nums, TreeNode* &p) {
        if(l > r) return;
        int m = (l + r) / 2;
        p = new TreeNode(nums[m]);
        build(l, m-1, nums, p->left);
        build(m+1, r, nums, p->right);
    }
};
int main() {
    vector<int> input;
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            input.push_back(t);

        }
        Solution s;
        TreeNode *root = s.sortedArrayToBST(input);
        cout<<root->val<<endl;
    }
}