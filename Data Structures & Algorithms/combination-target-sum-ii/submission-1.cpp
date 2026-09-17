#include<vector>
#include<iostream>
#include<queue>
#include<utility>
#include<random>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int target, int i, vector<int>& curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0 || i>= nums.size())
            return; 
        curr.push_back(nums[i]);
        backtrack(nums, target - nums[i], i+1, curr);
        curr.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        backtrack(nums, target, i+1, curr);

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target){
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, curr);
        return ans;
    }
};