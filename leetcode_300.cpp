class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        int ret = 0;
        //定义nums数组长度大小的数组，dp[i]表示nums[i]之前最长的连续子序列
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            if(ret < dp[i]) {
                ret = dp[i];
            }
        }
        return ret;
    }
};