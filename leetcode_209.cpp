class Solution {
public:
    // 双指针法
    // 定义 start 和 end ，计算区间[start, end]的和，如果大于 s ，算出最小连续数组，start++
    int minSubArrayLen(int s, vector<int>& nums) {
        int ret = INT_MAX;
        int sz = nums.size();
        if(sz == 0)
            return 0;
        
        int start = 0;
        int end = 0;
        int sum = 0;
        while(end < sz) {
            sum += nums[end];
            while(sum >= s) {
                ret = min(ret, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ret == INT_MAX? 0 : ret;
    }
};