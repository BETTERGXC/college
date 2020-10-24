class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() <= 0)
            return {};
        
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};