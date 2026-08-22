class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;

        int half = (total+1) / 2;
        int i = 0;
        int l = 0;
        int r = m;
        int j = 0;
            while(true){
            i = l + (r - l) / 2;    
            j = half - i;
            int left1 = (i == 0) ? INT_MIN : nums1[i-1];
            int right1 = (i == m) ? INT_MAX : nums1[i];
            int left2 = (j == 0) ? INT_MIN : nums2[j-1];
            int right2 = (j == n)? INT_MAX : nums2[j];
            if(left1 <= right2 && left2 <= right1){
                if(total % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            else if(left1 > right2)
                r = i - 1;
            else
                l = i + 1;

        }
    }
};
