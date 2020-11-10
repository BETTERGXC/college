class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(auto& e : nums)
            m[e]++;
        
        int ret;
        for(auto& e : nums) {
            if(m[e] == 1)
                ret = e;
        }
     
        return ret;
    }
};