class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backtrack(candidates, target, 0, 0, used);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, int sum, int start, vector<bool> used) {
        if(sum > target) {
            return;
        }
        if(sum == target) {
            result.push_back(tmp);
            return;
        }
        
        for(int i = start; i < candidates.size(); i++) {
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if(i >= 1 && candidates[i] == candidates[i-1] && used[i-1] == false) 
                continue;
            tmp.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtrack(candidates, target, sum, i+1, used);
            used[i] = false;
            sum -= candidates[i];
            tmp.pop_back();
        }
    }
};