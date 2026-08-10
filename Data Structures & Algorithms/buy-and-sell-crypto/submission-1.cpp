#include <bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_profit;
        int max_profit = 0;
        int price_to_buy = prices[0];
        for(int i = 1; i < prices.size(); i++){
            current_profit = prices[i] - price_to_buy;
            max_profit = max(max_profit, current_profit);
            price_to_buy = min(price_to_buy, prices[i]);
        }
        return max_profit;
    }
};