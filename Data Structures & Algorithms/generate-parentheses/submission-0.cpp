class Solution {
public:
    vector<string> ans;

    void dfs(string& current_string, int open, int close, int curr, int n){
        if(curr > 2 * n) return;
        if(close > open)
            return;
        if( open == close && curr == 2 * n ){
            ans.push_back(current_string);
            return;
        }
        current_string += "(";
        dfs(current_string, open + 1, close, curr + 1, n);
        current_string.pop_back();
        current_string += ")";
        dfs(current_string, open, close + 1, curr + 1, n);
        current_string.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(s, 0, 0, 0, n);
        return ans;
    }
};