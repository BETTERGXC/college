// 判断括号是否合法
bool chkParenthesis(string A, int n) {
    // write code here
    int left = 0;
    for (auto e : A) {
        if (e == '(')
            ++left;
        if (e == ')') {
            if (left > 0) {
                --left;
            }
            else {
                return false;
            }
        }

    }
    if (left == 0) {
        return true;
    }
    return false;
}
