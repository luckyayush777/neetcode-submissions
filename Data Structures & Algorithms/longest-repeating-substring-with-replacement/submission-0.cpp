class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        unordered_map<char, int> freq_map;
        int current_length = 0;
        int max_length = 0;
        int max_freq = 0;
        while(right < s.size()){
            freq_map[s[right]]++;
            if(freq_map[s[right]] > max_freq)
                max_freq = freq_map[s[right]];
            if(((right - left + 1) - max_freq ) <= k){
                current_length = right - left + 1;
                max_length = max(max_length, current_length);
            }else {
                freq_map[s[left]]--;
                left++;
            }
            right++;
        }
        return max_length;

    }
};
