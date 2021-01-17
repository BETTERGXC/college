class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp; 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ret;
    }

    void dfs(vector<int> &candidates, int idx, int target) {
        if(target == 0) {
            ret.push_back(tmp);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            dfs(candidates, i, target-candidates[i]);
            tmp.pop_back();
        }

    }
};