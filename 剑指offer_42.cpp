class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = -100;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > max) {
                max = sum;
            }
            if(sum < 0) {
                sum = 0;
            }
            
        }
        return max;
    }
};