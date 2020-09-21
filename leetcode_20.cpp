class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) 
            return true;
        stack<char> tmp;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                tmp.push(s[i]);
            }
            else {
                char t;
                if(!tmp.empty())
                    t = tmp.top();
                else
                    t = ' ';
                tmp.pop();
                if(s[i] == ')') {
                    if(t != '(')
                        return false;
                }
                if(s[i] == ']') {
                    if(t != '[')
                        return false;
                }
                if(s[i] == '}') {
                    if(t != '{')
                        return false;
                }
            }
        }
        if(tmp.empty())
            return true;
        return false;
    }
};