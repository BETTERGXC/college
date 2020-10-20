class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        vector<int> ret;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();
        while(left < right && top < bottom) {
            for(int i = left; i < right; i++) {
                ret.push_back(matrix[top][i]);
            }

            for(int i = top + 1; i < bottom; i++) {
                ret.push_back(matrix[i][right - 1]);
            }
            if(left < right - 1 && top < bottom - 1) {
                for(int i = right - 2; i >= left; i--) {
                    ret.push_back(matrix[bottom - 1][i]);
                }

                for(int i = bottom - 2; i > top; i--) {
                    ret.push_back(matrix[i][left]);
                }
            }
            
            left++;
            right--;
            top++;
            bottom--;
        }
        return ret;
    }
};