// https://www.nowcoder.com/practice/f1f6a1a1b6f6409b944f869dc8fd3381?tpId=117&tqId=37815&tab=answerKey
/*
根据贪心的思路，字典序小的放在前面比较优秀。比如"abc"放到"bca"的前面更好。
但是这样有个问题，就是字符串长度的问题，比如"bc""bca"此时应该将字典序大的"bca"放到前面。
为了解决此问题，不能直接按字典序排序，但是我们可以按照两个字符串连起来后的字符串的字典序排序。
比如"bc""bca",比较"bcbca"和"bcabc"那个字典序小，来确定"bc""bca"的位置。
*/ 
class Solution {
public:
    static bool cmp(const string str1, const string str2) {
        return (str1+str2) < (str2+str1);
    }
    string minString(vector<string>& strs) {
        string res;
        sort(strs.begin(), strs.end(), cmp);
        for(auto e : strs) {
            res += e;
        }
        return res;
    }
}; 
