class Solution {
public:
/*
    考虑三种情况
    1. 不考虑开头和末尾
    2. 不考虑开头
    3. 不考虑末尾
    因为情况 2 和情况 3包含了情况1，所以只用判断情况 2 和 3
    比较出情况 2 和情况 3中的最大值返回即可
*/
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int ret1 = _rob(0, nums.size() - 2, nums);
        int ret2 = _rob(1, nums.size() - 1, nums);
        return max(ret1, ret2);
    }
    int _rob(int start, int end, vector<int>& nums) {
        if(start == end)
            return nums[start];
        int len = nums.size();
        vector<int> dp(len);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for(int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[end];
    }
};