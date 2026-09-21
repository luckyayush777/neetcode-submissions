class Solution {
public:
    vector<vector<string>> ans;
    bool is_pal(const string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(const string& s, int i, vector<string> cur){
        if(i >= s.length()){
            ans.push_back(cur);
            return;
        }
        for(int j = i; j < s.length(); j++){
            if(is_pal(s, i, j)){
                cur.push_back(s.substr(i, j - i + 1));
            
            dfs(s, j+1, cur);
            cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        dfs(s, 0, cur);
        return ans;
    }
};
