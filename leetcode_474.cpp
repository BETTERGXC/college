class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
       
        for(string str : strs) {
            int OneNum = 0;
            int ZeroNum = 0;
            for(char c : str) {
                if(c == '0') 
                    ZeroNum++;
                else 
                    OneNum++;
            }

            for(int i = m; i >= ZeroNum; i--) {
                for(int j = n; j >= OneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-ZeroNum][j-OneNum] + 1);
                }
            }
        }

        return dp[m][n];
    }
};