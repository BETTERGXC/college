// 用一个visited数组来记录已经遍历过的字符的状态 

class Solution {
public:
    set<string> ret;
    string tmp;
    
    void backtrack(string str,vector<bool> visited) {
        if(tmp.size() == str.size()) {
            ret.insert(tmp);
            return;
        }
        for(int i = 0; i < str.size(); i++) {
            if(!visited[i]) {
                tmp += str[i];
                visited[i] = true;
                backtrack(str, visited);
                visited[i] = false;
                tmp.pop_back();
            }
            
        }
    }
    
    vector<string> Permutation(string str) {
        vector<bool> visited(str.size(),false);
        backtrack(str,visited);
        vector<string> ans(ret.begin(), ret.end());
        return ans;
    }
};
