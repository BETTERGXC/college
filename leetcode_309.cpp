class Solution {
public:
    // dp[i][0] 表示第i天持有股票
    // di[i][1] 表示第i天不持有股票
    // dp[i][2] 表示第i天不持有股票 且处在冷冻期
    // 冷冻期概念，今天卖出了，明天不可以买股票
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(3));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = dp[i-1][0] + prices[i];
        } 
        return max(dp[len-1][1], dp[len-1][2]);
    }
};