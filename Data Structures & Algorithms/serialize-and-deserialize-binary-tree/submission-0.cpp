class Codec {
public:

    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();

            for(int i = n; i > 0; i--){
                TreeNode* front = q.front();
                if(!front){
                    ans += "#,";
                }else{
                    ans += to_string(front->val) + ",";
                }
                q.pop();

                if(front){
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return ans;
    }


    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;

        getline(ss, token, ',');

        if(token == "#" || token.empty()){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(getline(ss, token, ',') && token != "#"){
                current->left = new TreeNode(stoi(token));
                q.push(current->left);
            }
            if(getline(ss, token, ',') && token != "#"){
                current->right = new TreeNode(stoi(token));
                q.push(current->right);
            }
            
        }
        return root;
    }
    
};