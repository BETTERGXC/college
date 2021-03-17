int dp(int n, int k) {
      if (n < 1 || k < 1)
            return 0;
      if (k == 1)
            return n;
      vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
      for (int i = 1; i < n + 1; i++) {
            dp[i][1] = i;
      }
      for (int i = 1; i < k + 1; i++) {
            dp[1][i] = 1;
      }
      for (int i = 2; i < n + 1; i++) {
            for (int j = 2; j < k + 1; j++) {
                  int mins = INT_MAX; 
                 for (int m = 1; m < i + 1; m++) {           
                       
                        mins = min(mins, max(dp[m-1][j-1], dp[i-m][j] ));
                  }
                  dp[i][j] = mins + 1;
            }
      }
      return dp[n][k];
}