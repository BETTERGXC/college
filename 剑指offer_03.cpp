class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto e : nums) {
            m[e]++;
        }
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(m[nums[i]] > 1) {
                ret = nums[i];
                break;
            }
                
        }
        return ret;
    }
};