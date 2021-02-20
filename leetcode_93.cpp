class Solution {
public:
    vector<string> res;
    vector<int> ip;
    #define IPCOUNT 4
    vector<string> restoreIpAddresses(string s) {
        ip.resize(IPCOUNT);
        backtrack(s, 0, 0);
        return res;
    }

    void backtrack(string s, int start, int ip_id) {
        if(ip_id == 4) {
            if(start == s.size()) {
                string tmp;
                for(int i = 0; i < 4; i++) {
                    tmp += to_string(ip[i]);
                    if(i != 3) {
                        tmp += '.';
                    }
                }
                res.push_back(tmp);
            }
            return;
        }

        if(start == s.size()) {
            return;
        }

        if(s[start] == '0') {
            ip[ip_id] = 0;
            backtrack(s, start + 1, ip_id + 1);
        }

        int ans = 0;
        for(int i = start; i < s.size(); i++) {
            ans = 10*ans + (s[i] - '0');
            if(ans > 0 && ans < 256) {
                ip[ip_id] = ans;
                backtrack(s, i+1, ip_id+1);
            }
            else {
                break;
            }
            
        }
    }
};
