class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int index = 0;
        for(int i = 0;i<nums.size();++i) {
            if(nums[index] != nums[i]) {
                nums[++index] = nums[i];
            }
        } 
        // 返回的是数组长度，index本来是数组下标，所以要再加加
        return ++index;
    }
};