class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        bool dp[A.length()][A.length()];
        for(int i = 0; i < A.length(); i++) {
            dp[i][i] = true;
        }
        int max = 0;
        for(int j = 1; j < A.length(); j++) {
            for(int i = 0; i < A.length() - 1 && i < j; i++) {
                if(A[i] != A[j]) {
                    dp[i][j] = false;
                }
                else {
                    if(j - i < 3) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] && j-i+1>max) {
                max = j-i+1;
                }
            }
            
        }
        return max;
    }
};