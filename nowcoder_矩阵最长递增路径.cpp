class Solution {
public:
    int dfs(vector<vector<int> >& matrix, vector<vector<int>>& visited,int i, int j ) {
        if(visited[i][j] != 0) {
            return visited[i][j];
        } 
        int cur = 0;
        // 向上下左右四个位置走
        // cur 为什么要max比较出最大的，因为可能进入多个判断
        if(i > 0 && matrix[i][j] > matrix[i - 1][j]){
            cur =  max(cur, dfs(matrix, visited, i - 1, j));
        }
        if(i + 1 < matrix.size() && matrix[i][j] > matrix[i + 1][j]){
            cur = max(cur, dfs(matrix, visited, i + 1, j));
        }
        if(j > 0 && matrix[i][j] > matrix[i][j - 1]){
            cur = max(cur, dfs(matrix, visited, i, j - 1));
        }
        if(j + 1 < matrix[0].size() && matrix[i][j] > matrix[i][j + 1]){
            cur = max(cur, dfs(matrix, visited, i, j + 1));
        }
        cur += 1;
        visited[i][j] = cur;
        return cur;
    }
    int solve(vector<vector<int> >& matrix) {
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(),0));
        int res = 0;
        // 以每一个位置为起点，进行计算
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                res = max(res, dfs(matrix, visited, i, j));
            }
        }
        return res;
    }
};
