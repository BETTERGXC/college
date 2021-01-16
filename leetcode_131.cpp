class Solution {
public:
    vector<vector<string>> ret;
    vector<string> tmp;
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while(begin <= end) {
            if(s[begin] != s[end]) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }  
    vector<vector<string>> partition(string s) {
        dfs(s, 0, s.size()-1);
        return ret;

    }
    void dfs(string s, int begin, int end) {
        if(begin > end) {
            ret.push_back(tmp);
            return;
        }
        for(int i = begin; i < s.size(); i++) {
            if(!isPalindrome(s.substr(begin, i-begin+1))) {
                continue;
            }
            tmp.push_back(s.substr(begin, i-begin+1));
            dfs(s, i+1, end);
            tmp.pop_back();
            
        }
    }
};