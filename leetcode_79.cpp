class Solution {
public:
    vector<vector<int>> next{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, 
    int i, int j, string& word, int k) {
        if(board[i][j] != word[k]) {
            return false;
        }
        else if(k == word.size()-1) {
            return true;
        }
        visited[i][j] = true;
        bool ret = false;
        for(auto& e : next) {
            int nexti = i + e[0];
            int nextj = j + e[1];
            if(nexti >= 0 && nexti < board.size() && nextj >= 0 && nextj < board[0].size()) {
                if(!visited[nexti][nextj]) {
                    bool flag = check(board, visited, nexti, nextj, word, k+1);
                    if(flag) {
                        ret = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size();
        int l = board[0].size();
        vector<vector<bool>> visited(h,vector<bool>(l));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < l; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if(flag) {
                    return true;
                }
            }
        }
        return false;
    }
};