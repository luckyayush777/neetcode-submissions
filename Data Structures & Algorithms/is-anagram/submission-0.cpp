#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
            unordered_map<char, int> freqMap1;
            if(s.size() != t.size())
                return false;
            for(auto& i : s){
                freqMap1[i]++;
            }
            for(auto& j : t){
                freqMap1[j]--;
                if(freqMap1[j] < 0)
                    return false;
            }

            for(int i = 0; i < freqMap1.size(); i++){
               if(freqMap1[i] > 0)
                    return false;
            }
            return true;

    }
};
