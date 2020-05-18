class Solution {
public:
    string reverseStr(string s, int k) {
        string str;
        for(int i = 0;i<s.length();i += 2*k) {
            // 如果剩余字符少于 k 个，则将剩余字符全部反转。
            if(s.length() - i < k) {
                reverse(s.begin() + i,s.end());
            }
            // 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
            else {
                reverse(s.begin() + i,s.begin() + i + k);
            }
        }
        str = s;
        return str;
    }
};