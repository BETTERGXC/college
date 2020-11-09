class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int,int> m;
        for(auto& e : nums) {
            m[e]++;
        }

        return m[target];
    }
};