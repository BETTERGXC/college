class Solution {
public:
    int climbStairs(int n) {
        // 状态转移方程 f(x) = f(x - 1) + f(x - 2)
        // 当 x = 0时，f(0) = 1;
        // 当 x = 1时，f(1) = 1;
        
        int f = 1;
        int p = 0;
        int q = 0;
        for(int i = 0; i < n; ++i) {
            p = q;
            q = f;
            f = p + q;
        }
        return f;
    }
};