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
    int k = 0;
    vector<int> nums;
    void inOrderTillK(TreeNode* root){
        if(!root) return;
        inOrderTillK(root->left);
        nums.push_back(root->val);
        inOrderTillK(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrderTillK(root);
        return nums[k-1];
    }
};
