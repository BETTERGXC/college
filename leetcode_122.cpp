//̰���㷨
//�ֲ����ţ��ռ�ÿ���������ȫ�����ţ����������� 
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


//��̬�滮
//dp[i][0] ��ʾ�� i ����й�Ʊ
//dp[i][1] ��ʾ�� i �첻���й�Ʊ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++) {
        	//dp[i][0] Ҫô����ǰһ����е�״̬��Ҫô��������
			//�����첻���е���������ȥ�������뻨��Ǯ 
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            //dp[i][1] Ҫô����ǰһ�첻���е�״̬��Ҫô��������
			//��������е����������Ͻ���������õ����� 
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[len-1][1];
    }
}; 
