// https://www.nowcoder.com/practice/7d21b6be4c6b429bb92d219341c4f8bb?tpId=117&tqId=37823&tab=answerKey 


class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        dp[0][0] = matrix[0][0];
        for(int i = 1; i < matrix.size(); i++) {
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }
        for(int j = 1; j < matrix[0].size(); j++) {
            dp[0][j] = dp[0][j-1] + matrix[0][j];
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[matrix.size() - 1][matrix[0].size() - 1];
    }
};
