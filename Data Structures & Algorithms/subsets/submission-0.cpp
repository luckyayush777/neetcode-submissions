#include<vector>
#include<iostream>
#include<queue>
#include<utility>
#include<random>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int i, vector<int> curr){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums, i + 1, curr);
        curr.pop_back();
        backtrack(nums, i+1, curr);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr = {};
        backtrack(nums, 0, curr);
        return ans; 
    }
};