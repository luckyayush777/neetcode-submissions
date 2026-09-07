class Solution {
public:
    int count = 0;
    int ans = 0;
    void inOrderTillK(TreeNode* root, int k){
        if(!root || count >= k) return;
        inOrderTillK(root->left, k);
        if(count >= k) return;
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        
        inOrderTillK(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrderTillK(root, k);
        return ans;
    }
};