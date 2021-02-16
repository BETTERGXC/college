class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(auto price : prices) {
            minPrice = min(price, minPrice);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};