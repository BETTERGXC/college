class Solution {
public:
	/* 
		dp数组的含义：dp[i][j]表示 长度为[0, i-1]和[0, j-1]的字符串的最长公共子序列为dp[i][j] 
		递推公式：
			if(text1[i] == text2[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
		 	}
		 	如果text1[i-1]与text2[j-1]不相同，那就看看text1[0, i-2]与text[0, j-1]的最长公共子序列
			和text1[0, i-1]与text2[0, j-2]的最长公共子序列，取最大的 
		 	else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
			}
	*/ 
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        if (!len1 || !len2)
            return 0;

        int dp[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= len2; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[len1][len2];
    }
};
