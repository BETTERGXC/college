class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 将所有的元素放到 unordered_map 中统计次数
        // 如果有任意一个元素的次数大于等于2，则flag = 1，返回true

        if(nums.size() == 0) {
            return false;
        }
        unordered_map<int,int> m;
        for(auto& e : nums) {
            m[e]++;
        }

        int flag = 0;
        for(auto& e : m) {
            if(e.second >= 2) {
                flag = 1;
            }
        }
        if(flag == 1)
            return true;
        else 
            return false;
    }
};