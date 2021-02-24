class CombinationIterator {
public:
    vector<string> ans;
    string tmp;
    int cur = 0;
    CombinationIterator(string characters, int combinationLength) {
        backtrack(characters, combinationLength, 0);
    }

    void backtrack(string characters, int combinationLength, int start) {
        if(tmp.size() == combinationLength) {
            ans.push_back(tmp);
            return;
        }
        for(int i = start; i < characters.size(); i++) {
            tmp += characters[i];
            backtrack(characters, combinationLength, i+1);
            tmp.pop_back();
        }
    }
    
    string next() {
        if(cur < ans.size()) {
            return ans[cur++];
        }
        return "";
    }
    
    bool hasNext() {
        return cur < ans.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */