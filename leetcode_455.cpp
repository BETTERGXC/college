class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;
        int pos = s.size() - 1;
        for(int i = g.size() - 1; i >= 0; i--) {
            if(pos >= 0 && s[pos] >= g[i]) {
                result++;
                pos--;
            }
        }
        return result;

    }
};