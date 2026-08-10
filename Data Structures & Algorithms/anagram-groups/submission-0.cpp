#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqMap;
        for(auto& element : strs){
            string originalElement = element;
            sort(element.begin(), element.end());
            if(freqMap.find(element) != freqMap.end()){
                freqMap[element].push_back(originalElement);
            } else {
                freqMap[element] = {originalElement};
            }
        }
        vector<vector<string>> ans;
        for(auto& entry : freqMap){
            ans.push_back(entry.second);
        }
        return ans;
    }
};



