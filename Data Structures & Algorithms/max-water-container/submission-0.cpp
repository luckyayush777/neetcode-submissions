#include <bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int current_water = 0;
        int max_water = 0;
        while(left < right){
            if(heights[left] > heights[right])
                {
                    current_water = heights[right] * (right - left);
                    max_water = max(max_water, current_water);
                    right--;
                }
            else
                {
                    current_water = heights[left] * (right - left);
                    max_water = max(max_water, current_water);
                    left++;
                }

        }
        return max_water;
    }
};
