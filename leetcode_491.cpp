class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    void backtrack(vector<int>& nums, int start) {
        if(path.size() > 1)
            result.push_back(path);
        
        unordered_set<int> uset;
        for(int i = start; i < nums.size(); i++) {
            if(!path.empty() && nums[i] < path.back()
                    || uset.find(nums[i]) != uset.end())
                continue;
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};