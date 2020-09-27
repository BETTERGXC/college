class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ret;
        for(auto e : nums) {
            m[e]++;
        }
        /*
        for(auto it = m.begin(); it != m.end(); ++it) {
            if(it->second == 1)
                ret.push_back(it->first);
        }
        */

        for(auto e : m) {
            if(e.second == 1)
               ret.push_back(e.first);
        }
        return ret;
    }
};