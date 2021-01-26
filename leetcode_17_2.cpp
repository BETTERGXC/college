class Solution {
public:
    const string LetterMap[10] = {
        "",      // 0
        "",      // 1  
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz"   // 9
    };

    vector<string> result;
    string tmp;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) 
            return result;
        backtrack(digits, 0);
        return result;
    }

    void backtrack(string digits, int index) {
        if(index == digits.size()) {
            result.push_back(tmp);
            return;
        }

        int digit = digits[index] - '0';
        string letter = LetterMap[digit];
        for(int i = 0; i < letter.size(); i++) {
            tmp += letter[i];
            backtrack(digits, index+1);
            tmp.pop_back();
        }
    }
};