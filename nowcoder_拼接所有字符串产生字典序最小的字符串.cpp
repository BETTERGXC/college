// https://www.nowcoder.com/practice/f1f6a1a1b6f6409b944f869dc8fd3381?tpId=117&tqId=37815&tab=answerKey
/*
����̰�ĵ�˼·���ֵ���С�ķ���ǰ��Ƚ����㡣����"abc"�ŵ�"bca"��ǰ����á�
���������и����⣬�����ַ������ȵ����⣬����"bc""bca"��ʱӦ�ý��ֵ�����"bca"�ŵ�ǰ�档
Ϊ�˽�������⣬����ֱ�Ӱ��ֵ������򣬵������ǿ��԰��������ַ�������������ַ������ֵ�������
����"bc""bca",�Ƚ�"bcbca"��"bcabc"�Ǹ��ֵ���С����ȷ��"bc""bca"��λ�á�
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
