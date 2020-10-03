class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;
        vector<vector<int>> v;
        v.resize(grid.size());
        for(int i = 0; i < grid.size(); i++) {
            v[i].resize(grid[0].size());
        }
        for(int i = 0; i < v.size(); i++) {
            if(i > 0) {
                v[i][0] = grid[i][0] + v[i-1][0];
            }
            else {
                v[i][0] = grid[i][0];
            }
            
        }
        for(int i = 0; i < v[0].size(); i++) {
            if(i > 0) {
                v[0][i] = grid[0][i] + v[0][i-1];
            }
            else {
                v[0][i] = grid[0][i];
            }
        }
        for(int i = 1; i < v.size(); i++) {
            for(int j = 1; j < v[0].size(); j++) {
                v[i][j] = max(v[i][j-1], v[i-1][j]) + grid[i][j];
            }
        }
        return v[m][n];
        
    }
};