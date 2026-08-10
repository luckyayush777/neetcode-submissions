#include<string>
#include<unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<char, int> freq_map;
        int ans = 0;
        for(int right = 0; right < s.size(); right++){
            freq_map[s[right]]++;
                while(freq_map[s[right]] > 1){
                    freq_map[s[left]]--;
                    left++;
                }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
