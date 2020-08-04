class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());

        vector<int>ret;

        for(auto& e : s1) {
            for(auto& f : s2) {
                if(e == f) {
                    ret.push_back(e);
                }
            }
        }

        return ret;
    }
};