#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for(auto& i : nums){
            freqMap[i]++;
            if(freqMap[i] > 1)
                return true;
        }
        return false;
    }
};