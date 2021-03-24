class Solution {
public:
	/* 
		dp����ĺ��壺dp[i][j]��ʾ ����Ϊ[0, i-1]��[0, j-1]���ַ����������������Ϊdp[i][j] 
		���ƹ�ʽ��
			if(text1[i] == text2[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
		 	}
		 	���text1[i-1]��text2[j-1]����ͬ���ǾͿ���text1[0, i-2]��text[0, j-1]�������������
			��text1[0, i-1]��text2[0, j-2]������������У�ȡ���� 
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
