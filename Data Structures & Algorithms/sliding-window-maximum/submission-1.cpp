class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        multiset<int> tree;
        int l = 0, r = 0;
        int cwc = 0;
        int current_max = INT_MIN;
        while(r < nums.size()){
            while(cwc < k){
                tree.insert(nums[r]);
                r++;
                cwc++;
            }
            //window reset
            auto left_iterator = tree.find(nums[l]);
            current_max = *tree.rbegin(); 
            result.push_back(current_max);
            tree.erase(left_iterator);
            l++;
            cwc--;
            

        }
        return result;
    }
};
