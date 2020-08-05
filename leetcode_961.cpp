class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int ret;
        unordered_map<int,int> m;
        for(auto& e : A) {
            m[e]++;
        }
        for(auto& e : m) {
            if(e.second == A.size() / 2) {
                ret = e.first;
            }
        }
        return ret;
    }
};