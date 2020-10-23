class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() <= 0)
            return {};
        vector<int> ret(nums);
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            while(left < right && ret[left] % 2 != 0) {
                left++;
            }
            while(left < right && ret[right] % 2 == 0) {
                right--;
            }
            swap(ret[left], ret[right]);
        }

        return ret;
    }
};