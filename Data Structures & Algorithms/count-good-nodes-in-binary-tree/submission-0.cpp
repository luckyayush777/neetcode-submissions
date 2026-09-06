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
    int ans = 0;
    void helper(TreeNode* root, int current_max){
        if(!root) return;
        if(root && root->val >= current_max){
            ans++;
            current_max = root->val;
        }
        helper(root->left, current_max);
        helper(root->right, current_max);
    }
    int goodNodes(TreeNode* root) {
        int current_max = INT_MIN;
        helper(root, current_max);
        return ans;
        
    }
};
