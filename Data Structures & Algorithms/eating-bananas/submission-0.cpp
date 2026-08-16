class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile_size = INT_MIN;
        for(auto& element : piles){
            if(element > max_pile_size)
                max_pile_size = element;
        }
        int l = 1;
        int r = max_pile_size;
        long long t;
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            t = 0;
            for(auto& pile : piles){
                t += (pile + mid - 1) / mid;
            }
            if(t <= h){
                if(ans == 0 || mid < ans){
                    ans = mid;
                }
                r = mid - 1;
            }
            else if(t > h){
                l = mid + 1;
            }
            

        }
        return ans;
    }
};