class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, nums[i] + i);
            if(farthest <= i)
                return false;
        }
        return farthest >= nums.size() - 1;
    }
};