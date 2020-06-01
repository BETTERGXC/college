// 反转字符串中的单词

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return s;
        int begin = 0;
        int pos = 0;
        while (pos <= s.size() - 1) {
            while (s[pos] != ' ') {
                ++pos;
                if (pos == s.size())
                    break;
            }
            int end = pos - 1;
            while (begin < end) {
                swap(s[begin], s[end]);
                ++begin;
                --end;
            }
            begin = pos + 1;
            ++pos;
        }
        return s;
    }
};