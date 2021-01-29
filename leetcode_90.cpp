class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, used);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<bool>& used) {
        result.push_back(path);
        for(int i = start; i < nums.size(); i++) {
            // 如果是重复的，则跳过
            // nums[i] == nums[i-1]时
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 同一树层不能使用相同元素，所以跳过
            if(i >= 1 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};