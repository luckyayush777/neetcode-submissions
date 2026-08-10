
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int l = 0, r = 0;
        int current_window_size = 0;
        unordered_map<char, int> fm;
        while(r < n && l <= n - m){
            while(current_window_size < m){
            fm[s2[r]]++;
            current_window_size++;
            r++;
            }
            for(auto& element : s1){
                fm[element]--;
            }
            bool all_zero = true;
            for(auto& pair : fm){
                if(pair.second != 0)
                {
                    all_zero = false;
                    break;
                }
            }
            if(all_zero)
                return true;
            l++;
            r = l;
            fm.clear();
            current_window_size = 0;

        }
        return false;
    }
};