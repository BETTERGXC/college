class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s.size();
        int maxLen = 0;
        int begin = 0;
        for(int i = 1; i < s.size(); i++) {
            for(int j = begin; j < i; j++) {
                if(s[j] == s[i]) {
                    begin = j+1;
                    break;
                }
            }

            maxLen = max(maxLen, i-begin+1);
        }
        return maxLen;
    }
};