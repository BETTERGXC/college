//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
bool checkWon(vector<vector<int> > board) {
    // write code here
    int row = board.size();
    for (int i = 0; i < row; ++i) {
        int s_row = 0;
        int s_cow = 0;
        for (int j = 0; j < row; ++j) {
            s_row += board[i][j];
            s_cow += board[j][i];
        }
        if (s_row == row)
            return true;
        if (s_cow == row)
            return true;

    }
    int m = 0;
    int n = 0;
    for (int i = 0; i < row; ++i) {
        m += board[i][i];
        n += board[i][row - 1 - i];
        
    }
    if (m == row)
        return true;
    if (n == row)
        return true;

    return false;
}