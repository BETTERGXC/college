class Solution {
public:
    int fib(int n) {
        /*
        if(n == 0 || n == 1)
            return n;
        int f1 = 1;
        int f2 = 0;
        for(int i = 1; i < n; i++) {
            f1 = f1 + f2;
            f2 = f1 - f2;
            f1 %= 1000000007;
        }
        return f1;
        */

        if(n == 0 || n == 1)
            return n;
        vector<int> v(n+1);
        v[0] = 0;
        v[1] = 1;
        for(int i = 2; i < n+1; i++) {
            v[i] = (v[i-1] + v[i-2]) % 1000000007;
        }

        return v[n];
    }
};