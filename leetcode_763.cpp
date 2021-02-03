class Solution {
public:
    // 统计每一个字符最后出现的位置
    // 从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等，就是分割点
    vector<int> partitionLabels(string S) {
        int hash[27] = {0};
        for(int i = 0; i < S.size(); i++) {
            hash[S[i]-'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for(int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']);
            if(right == i) {
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return result;
    }
};