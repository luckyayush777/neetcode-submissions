#include<vector>
#include<iostream>
#include<queue>
#include<utility>
#include<random>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> nums, vector<int>& curr, int i){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs(nums, curr, i+1);
        while(i+1 < nums.size() && nums[i+1] == nums[i])
        i++;
        curr.pop_back();
        dfs(nums, curr, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        sort(nums.begin(), nums.end());
        dfs(nums, current, 0);

        return ans;
    }
};
