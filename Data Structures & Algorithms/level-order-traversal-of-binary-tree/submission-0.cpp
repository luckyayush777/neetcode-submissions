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
    vector<int> copyNumsFromNodes(vector<TreeNode*> in){
        vector<int> ans;
        for(auto& elem : in){
            ans.push_back(elem->val);
        }
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;
        
        
        bool all_empty = false;
        vector<TreeNode*> prev_list_nodes;
        prev_list_nodes.push_back(root);
        ans.push_back(copyNumsFromNodes(prev_list_nodes));
        while(!all_empty){
            vector<TreeNode*> current_list;
            for(auto& elem : prev_list_nodes){
                if(elem && elem->left != nullptr){
                    current_list.push_back(elem->left);
                }
                if(elem && elem->right != nullptr){
                    current_list.push_back(elem->right);
                }
                
            }
            if(current_list.size() == 0){
                all_empty = true;
            }else{
                prev_list_nodes = current_list;
                ans.push_back(copyNumsFromNodes(prev_list_nodes));
            }
        }
        return ans;

    }
};
