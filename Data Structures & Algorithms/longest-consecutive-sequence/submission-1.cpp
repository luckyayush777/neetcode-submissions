class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        unordered_set<int> nums_set;
        for(auto& element : nums){
            nums_set.insert(element);
        }
        int answer;
        int current_seq_length = 0;
        int current_seq_start = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums_set.find(nums[i] - 1) != nums_set.end())
            {
                //current_seq_length++;
                continue;
            }
            int start = nums[i];
            int current_seq_length = 0;
                while(nums_set.find(start + current_seq_length) != nums_set.end()){
                    current_seq_length++;
                }
                answer = max(answer, current_seq_length);  
        }
        return answer;
    }
};
