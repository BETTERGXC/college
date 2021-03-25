class Solution {
public:
/*
    dp[i][j]表示 0~i-1 0~j-1 有多少个相同的子序列
    如果 A[i-1] == B[j-1] 则 dp[i][j] = dp[i-1][j-1] +1
*/
    int findLength(vector<int>& A, vector<int>& B) {
        int Alen = A.size();
        int Blen = B.size();
        vector<vector<int>> dp(Alen+1, vector<int>(Blen+1, 0));
        int result = 0;
        for(int i = 1; i <= Alen; i++) {
            for(int j = 1; j <= Blen; j++) {
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if(dp[i][j] > result) {
                    result = dp[i][j];
                }
            }
        }
        return result;
    }
};