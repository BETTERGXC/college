class Solution {
public:
    vector<int> printNumbers(int n) {
        if(n <= 0) 
            return {};
        int k = 1;
        for(int i = 0; i < n; i++) {
            k = 10 *k;
        }

        k -= 1;
        vector<int> ret(k);
        for(int i = 1; i <= k; i++) {
            ret[i - 1] = i;
        }

        return ret;
    }
};