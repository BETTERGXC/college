// 转移方程是  minSum[i][j] = min(minSum[i - 1][j],minSum[i - 1][j - 1]) + triangle[i][j];
// 考虑到边界情况 所以有
// 当在最左边  minSum[i][j] = minSum[i - 1][j] + triangle[i][j];
// 当在最右边  minSum[i][j] = minSum[i - 1][j - 1] + triangle[i][j];

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
       if(triangle.empty())
           return 0;
        int row = triangle.size();
        
        vector<vector<int>> minSum(triangle);
        for(int i = 1; i < row; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j == 0) {
                    minSum[i][j] = minSum[i - 1][j] + triangle[i][j];
                }
                else if(j == i) {
                    minSum[i][j] = minSum[i - 1][j - 1] + triangle[i][j];
                }
                else {
                    minSum[i][j] = min(minSum[i - 1][j],minSum[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }
        // 找出最小的
        int ret = minSum[row - 1][0];
        for(int j = 0; j < row; ++j) {
            ret = min(ret,minSum[row - 1][j]);
        }
        return ret;
    }
};