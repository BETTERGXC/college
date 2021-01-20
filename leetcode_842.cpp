class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ret;
        backtrack(S, ret, 0, 0, 0);
        return ret;
    }

    bool backtrack(string& S, vector<int>& ret, int start, long long sum, int prev) {
        if(start == S.size()) {
            return ret.size() >= 3;
        }

        long long cur = 0;
        for(int i = start; i < S.size(); i++) {
            if(i > start && S[start] == '0') {
                break;
            }
            cur = cur*10 + S[i] - '0';
            if(cur > INT_MAX) {
                break;
            }
            if(ret.size() >= 2) {
                if(cur < sum) {
                    continue;
                }
                else if(cur > sum) {
                    break;
                }
            }
            ret.push_back(cur);
            if(backtrack(S, ret, i+1, prev+cur, cur) ) {
                return true;
            }
            ret.pop_back();

        }
        return false;
    }
};