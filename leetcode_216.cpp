class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n, k, 1);
        return ret;
    }
    void backtrack(int n, int k, int start) {
        if(k == 0) {
            if(0 == n) {
                ret.push_back(tmp);
            }
            return;
        }

        for(int i = start; i <= 9 && n-i >= 0 ; i++) {
            tmp.push_back(i);
            backtrack(n-i, --k, i+1);
            ++k;
            tmp.pop_back();
        }
        
    }
};