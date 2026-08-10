#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(auto& element : nums){
            freqMap[element]++;
        }
        vector<vector<int>> bucketOfLists(nums.size() + 1);
        for(auto& element : freqMap){
            bucketOfLists[element.second].push_back(element.first);
        }
        int count = 0;
        vector<int> ans;
        for(int i = bucketOfLists.size() - 1; i >= 1; i--){
            for(int j = 0; j < bucketOfLists[i].size(); j++){
                ans.push_back(bucketOfLists[i][j]);
                //count++;
                if(ans.size() == k)
                    return ans;
                    
            }
        }
        return ans;

    }
};
