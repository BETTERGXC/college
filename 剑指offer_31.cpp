class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pos = 0;
        for(auto e : pushed) {
            s.push(e);
            while(!s.empty() && s.top() == popped[pos]) {
                s.pop();
                ++pos;
            }
        }
        return s.empty();
    }
};