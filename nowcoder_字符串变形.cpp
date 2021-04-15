class Solution {
public:
    string trans(string s, int n) {
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && s[j] != ' ')
                j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        string res;
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ' && s[i] >= 'A' && s[i] <= 'Z')
                res += s[i] - 'A' + 'a';
            else if(s[i] != ' ' && s[i] >= 'a' && s[i] <= 'z')
                res += s[i] - 'a' + 'A';
            else
                res += s[i];
        }
        return res;
        
    }
};
