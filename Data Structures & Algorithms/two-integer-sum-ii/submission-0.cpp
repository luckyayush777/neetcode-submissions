class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> ans;
        while(start < end){
            int sum = numbers[start] + numbers[end];
            if(target < sum){
                end--;
            }else if(target > sum){
                start++;
            }
            else if(target == sum){
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                break;
            }
        }
        return ans;
    }
};
