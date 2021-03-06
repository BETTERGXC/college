class Solution {
public:

    //1.确定dp数组的含义
    /*
        dp[i][0]表示第i天没有操作
        dp[i][1]表示第i天第一次买入
        dp[i][2]表示第i天第一次卖出
        dp[i][3]表示第i天第二次买入
        dp[i][4]表示第i天第二次卖出
    */
    //2.dp数组的初始化
    /*
        dp[0][0] dp[0][2] dp[0][4]均应该等于0，因为第一天没有没有操作和第一天卖出都没有钱
        dp[0][1] dp[0][3]均等于 -price[0]
        因为第一天买入就应该资金就应该少这么多钱
    */
    //3.递推公式
    /*
        dp[i][0]是没有操作，没有操作只能保持前一天的状态
    */
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }
        return dp[len-1][4];
    }
    /*
     int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> dp(5, 0);
        dp[1] = -prices[0];
        dp[3] = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        return dp[4];
    }
    */
};