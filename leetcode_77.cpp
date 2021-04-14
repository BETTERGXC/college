class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(int n, int k, int start) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }
        for(int i = start; i <= n; i++) {
            path.push_back(i);
            backtrack(n, k, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return res;
    }
};
