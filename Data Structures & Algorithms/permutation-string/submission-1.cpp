
class Solution {
public:
    bool match(unordered_map<char, int>& fm, unordered_map<char, int>& fs){
        for(auto& element : fs){
            if(fm[element.first] != element.second){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int left = 0, right = 0;
        int current_window_size = 0;
        unordered_map<char, int> fm;
        unordered_map<char, int> fs;
        for(auto& element : s1){
            fs[element]++;
        }
        while(right < m && right < n){
            fm[s2[right]]++;
            right++;
        }
        if(match(fm, fs)){
            return true;
        }
        while(right < n && left <= n - m){
            fm[s2[left]]--;
            fm[s2[right]]++;
            left++;
            right++;
            if(match(fm, fs)){
                return true;
            }

        }
        return false;
    }
};