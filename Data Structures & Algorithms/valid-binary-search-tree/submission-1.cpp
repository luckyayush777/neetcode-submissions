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
    std::vector<int> nums;
    int ans = true;
    void preorder(TreeNode* root){
        if(!root) return;
        preorder(root->left);
        nums.push_back(root->val);
        if(nums.size() >= 2 && 
           nums[nums.size() - 1] <= nums[nums.size() - 2]){
            ans = false;
        }
        preorder(root->right);

    }
    bool isValidBST(TreeNode* root) {
        preorder(root);
        return ans;
    }
};
