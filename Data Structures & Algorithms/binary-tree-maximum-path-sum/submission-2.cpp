/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;

        int local_sum_child = INT_MIN;
        int local_sum_root_included = INT_MIN;
        int local_sum = 0;
        int left_sum = dfs(root->left);
        int right_sum = dfs(root->right);
        local_sum_root_included = root->val + max(0, right_sum) + 
        max(0, left_sum);
        local_sum_child = root->val + max(0, max(right_sum, left_sum));
        ans = max(ans, local_sum_root_included);
        return local_sum_child;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};