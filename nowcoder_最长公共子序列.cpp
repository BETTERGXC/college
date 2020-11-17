class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int len1 = str1.size();
        int len2 = str2.size();
        if(!len1 || !len2)
            return "-1";
        
        int dp[len1+1][len2+1];
        for(int i = 0; i <= len1; i++) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= len2; i++) {
            dp[0][i] = 0;
        }
        int max = 0;
        int start = 0;
        for(int i = 1; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                if(str1[i-1] == str2[j-2]) {
                    dp[i][j] = dp[i-1][j-1] +1;
                    
                }
                else {
                    dp[i][j] = 0;
                }
                if(dp[i][j] > max) {
                    max = dp[i][j];
                    start = i - max;
                }
            }
        }
        
        return str1.substr(start,max);
    }
};