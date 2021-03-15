class Solution {
public:
    // dp[i] 表示从从 哦到 i家可以偷到最多的钱
    // 状态转移方程：dp[i] = (dp[i-2] + nums[i], dp[i-1])
    // 要么偷第 i 家，要么不偷第 i家
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size() - 1];
    }
};