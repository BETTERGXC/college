class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0)
            return 0;
        vector<int> v(n,0);
        v[0] = 1;
        int i = 0;
        int j = 0;
        int k = 0;
        for(int index = 1; index < n; ++index) {
            int tmp = min(v[i] * 2,min(v[j] * 3, v[k] * 5));
            if(tmp == v[i] * 2)
                i++;
            if(tmp == v[j] * 3)
                j++;
            if(tmp == v[k] * 5)
                k++;
            v[index] = tmp;
        }
        return v[n-1];
    }
};