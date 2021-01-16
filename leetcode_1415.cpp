class Solution {
public:
    string str; 
    vector<string> ret;
    string getHappyString(int n, int k) {   
        dfs(n,k);
        if(ret.size() >= k) {
            return ret[k-1];
        }
        else {
            return "";
        }
        
    }

    void dfs(int n, int k) {
        if(str.size() == n) {
            ret.push_back(str);
            return;
        }
        if(ret.size() > k) {
            return;
        }
        for(int i = 'a'; i <= 'c'; i++) {
            if(str.back() == i)
                continue;
            str += i;
            dfs(n, k);
            str.pop_back();
        }
    }
};

