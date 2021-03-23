class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i+1] > nums[i]) {
                dp[i+1] = dp[i] + 1;
            }
            if(dp[i+1] > result) {
                result = dp[i + 1];
            }
        }
        return result;
    }
};