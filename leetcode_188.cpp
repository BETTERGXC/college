class Solution {
public:
    //除了0以外，偶数就是卖出，奇数就是买入。
    //题目要求是至多有K笔交易，那么j的范围就定义为 2 * k + 1
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2*k+1,0));
        for(int j = 1; j < 2*k; j += 2) {
            dp[0][j] = -prices[0];
        }

        for(int i = 1; i < len; i++) {
            for(int j = 0; j < 2*k-1; j += 2) {
                dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j] - prices[i]);
                dp[i][j+2] = max(dp[i-1][j+2], dp[i-1][j+1] + prices[i]);
            }
        }
        return dp[len-1][2*k];
    }
};