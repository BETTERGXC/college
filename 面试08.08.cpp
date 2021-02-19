class Solution {
public:
    vector<string> res;
    string tmp;
    unordered_set<string> set;
    vector<string> permutation(string S) {
        vector<int> visited(S.size(), 0);
        dfs(S, tmp, visited);
        return res;
    }

    void dfs(string S, string tmp, vector<int> visited) {
        if(tmp.size() == S.size()) {
            auto it = set.find(tmp);
            if(it == set.end()) {
                set.insert(tmp);
                res.push_back(tmp);
            }
            return;
        }

        for(int i = 0; i < S.size(); i++) {
            if(visited[i] == 1)
                continue;
            visited[i] = 1;
            tmp += S[i];
            dfs(S, tmp, visited);
            tmp.pop_back();
            visited[i] = 0;
        }
    }
};
