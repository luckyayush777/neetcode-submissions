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

struct Info{
    bool balanced;
    int height;
};

class Solution {
public:
    Info dfs(TreeNode* root){
        if(!root) return{true, 0};
        Info left = dfs(root->left);
        Info right = dfs(root->right);
        
        bool balanced = (left.balanced && right.balanced) && (abs(left.height - right.height) <= 1);
        int height = 1 + max(left.height, right.height);
        return {balanced, height};
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).balanced;        
    }
};
