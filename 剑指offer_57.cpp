class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.empty()) return {};
        int lo = 0, hi = nums.size()-1;
        while(lo<hi){
            if(nums[lo]+nums[hi]<target) lo++;
            else if(nums[lo]+nums[hi]>target) hi--;
            else return {nums[lo], nums[hi]};
        }
        return {};
    }
};