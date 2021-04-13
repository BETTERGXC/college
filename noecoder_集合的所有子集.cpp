class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        backTrack(S, 0);
        return ret;
    }
     
    void backTrack(vector<int> &S, int start) {
        ret.push_back(path);
        for(int i = start; i < S.size(); i++)  {
            path.push_back(S[i]);
            backTrack(S, i+1);
            path.pop_back();
        }
    }
};
