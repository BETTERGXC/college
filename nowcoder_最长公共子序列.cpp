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
        
        int dp[len1+1];
        memset(dp, 0, sizeof(dp));
        int max = 0;
        int start = 0;
     
        for(int i = 1; i <= len1; i++) {
            int pre = 0;
            for(int j = 1; j <= len2; j++) {
                int tmp = dp[j];
                if(str1[i-1] == str2[j-1]) {
                    dp[j] = pre +1;
                }
                else {
                    dp[j] = 0;
                }
                pre = tmp;
                
                if(dp[j] > max) {
                    max = dp[j];
                    start = i - max;
                }
            }
        }
        if(max == 0)
            return "-1";
        return str1.substr(start,max);
    }
};