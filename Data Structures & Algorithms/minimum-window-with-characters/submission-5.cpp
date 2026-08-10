class Solution {
public:
    bool is_ss(unordered_map<char, int>& fm1, unordered_map<char, int>& fm2){
        for(auto& element : fm2){
            if(fm1[element.first] < element.second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        unordered_map<char, int> fm_s;
        unordered_map<char, int> fm_t;
        int left = 0, right = 0;
        for(auto& element : t){
            fm_t[element]++;
        }
        int best_len = INT_MAX;
        int best_start = 0;
        std::string current_string = "";
        for(right = 0; right < s.size(); right++){
            fm_s[s[right]]++;
            while(is_ss(fm_s, fm_t)){
                int cwl = right - left + 1;
                if (cwl < best_len) {
                        best_len = cwl;
                    best_start = left;
                }
                fm_s[s[left]]--;
                left++;
            }
        }
        return best_len == INT_MAX ? "" : s.substr(best_start, best_len);
    }
};
