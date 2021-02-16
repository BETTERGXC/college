//贪心算法
//局部最优：收集每天的正利润，全局最优：求得最大利润 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i-1], 0);
        }
        return result;
    }
};
