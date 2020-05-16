

//  依次从头查找和从尾查找字符串s中的字符，如果从头查找的下标和从尾查找的下标相同，则这个字符只出现了一次。

class Solution {
public:
    int firstUniqChar(string s) {
        for(int i = 0;i<s.size();++i) {
            int index = s.find(s[i]);
            int r_index = s.rfind(s[i]);
            if(index == r_index) {
                return index;
            }
        }
        return -1;
        
    }
};