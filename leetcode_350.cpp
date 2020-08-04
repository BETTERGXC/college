class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        // 双指针法
        // 先把两个数组排序，然后两个指针遍历两个数组
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int pos1 = 0;
        int pos2 = 0;
        while(pos1 < nums1.size() && pos2 < nums2.size()) {
            if(nums1[pos1] < nums2[pos2]) {
                ++pos1;
            }
            else if(nums1[pos1] > nums2[pos2]) {
                ++pos2;
            }
            else {
                ret.push_back(nums1[pos1]);
                ++pos1;
                ++pos2;
            }
        }
        return ret;
        
        
    }
};