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
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> current;
            int size = q.size();

            for(int i = size; i--; i >= 0){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    current.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
                
            }
            if(!current.empty()){
                    ans.push_back(current[current.size() - 1]);
                }
        }
        return ans; 
    }
};
