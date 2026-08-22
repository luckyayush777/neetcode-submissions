class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //brute force
        int m = nums1.size();
        int n = nums2.size();
        vector<int> combined(m+n, 0);
        int current1 = 0;
        int current2 = 0;
        int idx = 0;
        while(current1 < m && current2 < n){
            if(nums1[current1] <= nums2[current2]){
                combined[idx] = nums1[current1];
                current1++;
            }else if(nums1[current1] > nums2[current2]){
                combined[idx] = nums2[current2];
                current2++;
            }
            idx++;
        }
        while(current2 < n){
            combined[idx] = nums2[current2];
            current2++;
            idx++;
        }
        while(current1 < m){
            combined[idx] = nums1[current1];
            current1++;
            idx++;
        }
        

        if(combined.size() % 2 == 0){
            return (combined[combined.size() / 2] + combined[(combined.size() / 2) - 1]) / 2.0;
        }else {
            return combined[combined.size()  / 2];
        }
    }
};
