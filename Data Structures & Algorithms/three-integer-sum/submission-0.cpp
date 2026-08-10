#include <vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i1, left, right;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(i1 = 0; i1 < nums.size(); i1++){
            if(i1 > 0 && nums[i1] == nums[i1 - 1]) continue; // Skip duplicates for the first number
            left = i1 + 1;
            right = nums.size() - 1;
            while(left < right){
                int sum = nums[i1] + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back({nums[i1], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates for the second number
                    while(left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates for the third number
                    left++;
                    right--;
                } else if(sum < 0){
                    left++;
                } else {        
                    right--;
                }
            }
        }
        return ans;
    }
};
