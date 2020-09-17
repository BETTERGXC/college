// 一个格子 只能通过这个格子上边的格子或者左边的格子到达
// 所以转移方程是 pathNum[i][j] = pathNum[i - 1][j] + pathNum[i][j - 1];
// 考虑两个边界情况  当格子在第一行，就没有办法从上边的格子到达
// 当格子在第一列就没办法从左边的格子到达

class Solution {
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        // write code here
        vector<vector<int>> pathNum;
        pathNum.reserve(m);
        
        for(int i = 0; i < m; ++i) {
            pathNum[i].reserve(n);
        }
        
        for(int i = 0; i < m; ++i) {
            pathNum[i][0] = 1;
        }
        for(int i = 0; i < n; ++i) {
            pathNum[0][i] = 1;
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                pathNum[i][j] = pathNum[i - 1][j] + pathNum[i][j - 1];
            }
        }
        
        return pathNum[m - 1][n - 1];
    }
};