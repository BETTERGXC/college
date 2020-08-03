class Solution {
public:
   
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> v;
        string str;
        // 将两个字符串拼接成一个字符串，然后查找只出现一次的单词
        str = A + ' ' + B;
        // 将所有的单词，放到数组中
        for(int i = 0;i<str.size();++i) {
            string temp;
            if(str[i] == ' ') 
                continue;
            while(i < str.size() && str[i] != ' ') {
                temp += str[i];
                ++i;
            }
            v.push_back(temp);
        }
        // 将所有的单词放到unordered_map中统计次数
        unordered_map<string,int> m;
        for(auto& e : v) {
            m[e]++;
        }
        // 将只出现一次的单词，放回数组中
        v.resize(0);

        for(auto& e : m) {
            if(e.second == 1)
                v.push_back(e.first);
        }
        
        return v;
    }
};