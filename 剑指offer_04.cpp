class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 行
        int row = matrix.size() - 1;
        // 列
        int col = 0;
        while(row >= 0 && col < matrix[0].size()) {
            if(matrix[row][col] < target) {
                ++col;
            }
            else if(matrix[row][col] > target) {
                --row;
            }
            else if(matrix[row][col] == target) {
                return true;
            }
        }  
        return false;
    }
};