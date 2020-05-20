class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (auto e : nums) {
            num ^= e;
        }
        return num;
    }
};