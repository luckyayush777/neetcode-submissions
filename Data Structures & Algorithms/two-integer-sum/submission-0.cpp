#include<iostream>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> freqMap;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(freqMap.find(target - nums[i]) != freqMap.end()){
                ans.push_back(freqMap[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            freqMap[nums[i]] = i;
        }
        return ans;
    }
};

