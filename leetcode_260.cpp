class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>res;
        int i = 0;
        sort(nums.begin(),nums.end());
        for(;i<nums.size() - 1;) {
            if(nums[i] == nums[i+1]) {
                i += 2;
            }
            else {
                res.push_back(nums[i]);
                i += 1;
            }
        }
        // i在循环中最大到达 size() - 1，但是无法将 size() - 1处的值加进ret
        if (i < nums.size()) {
            res.push_back(nums[i]);
        }
        return res;
    }
};