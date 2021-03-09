class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0];
        int maxRet = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            //这里需要保存一下状态，如果不保存的话，计算完 maxF， minF的值会受到影响
            int mx = maxF;
            int mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            maxRet = max(maxRet, maxF);
        }
        return maxRet;
    }
};