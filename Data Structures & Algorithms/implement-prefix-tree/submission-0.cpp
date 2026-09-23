struct Node{
    unordered_map<char, Node*> child;
    bool is_end = false;
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char c : word){
            
        if(cur->child.find(c) == cur->child.end()){
                // didnt find 
                Node* n;
                n = new Node();
                cur->child[c] = n;
            }
            cur = cur->child[c];

        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        Node* cur = root;   
        for(char c : word){
            
            if(cur->child.find(c) != cur->child.end())
                cur = cur->child[c];
            else if(cur->child.find(c) == cur->child.end()){
                return false;
            }

        }
            if(cur->is_end)
            return true;
        return false;
    }
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char c : prefix){
            if(cur->child.find(c) != cur->child.end())
                cur = cur->child[c];
            else if(cur->child.find(c) == cur->child.end()){
                return false;
            }

        }
        return true;
    }

};

