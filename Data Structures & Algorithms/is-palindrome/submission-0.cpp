class Solution {
public:
    bool isPalindrome(string s) {
       int l = 0, r = s.size() - 1;

       while(l < r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            else if(!isalnum(s[r])){
                r--;
                continue;
            }
            if(isalnum(s[l]) && isalnum(s[r])){
                s[l] = tolower(s[l]);
                s[r] = tolower(s[r]);
            }
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else if(s[l] != s[r]){
                return false;
            }
       }
       return true;
    }
};
