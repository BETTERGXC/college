class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1 && target == nums[0])
            return 0;
        else if(nums.size() == 1 && target != nums[0])
            return -1;
        
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[0] <= nums[mid]) {
                if(nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                if(nums[mid] < target && target <= nums[nums.size() - 1]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

