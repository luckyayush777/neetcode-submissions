
class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void dfs(string curr, int i, string& digits){
        if(i == digits.size()){
            ans.push_back(curr);
            return;
        }
        for(char c : m[digits[i]]){
            curr.push_back(c);
            dfs(curr, i + 1, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        string curr;
        dfs(curr, 0, digits);
        return ans;
    }
};
