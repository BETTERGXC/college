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


//动态规划
//dp[i][0] 表示第 i 天持有股票
//dp[i][1] 表示第 i 天不持有股票 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++) {
        	//dp[i][0] 要么保持前一天持有的状态，要么今天买入
			//用昨天不持有的最大利润减去今天买入花的钱 
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            //dp[i][1] 要么保持前一天不持有的状态，要么今天卖出
			//用昨天持有的最大利润加上今天卖出获得的利润 
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[len-1][1];
    }
}; 
