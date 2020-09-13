/*
状态递推：
在F(i,j)处需要考虑S[i] = T[j] 和 S[i] != T[j]两种情况
当S[i] = T[j]:
1>: 让S[i]匹配T[j]，则
F(i,j) = F(i-1,j-1)
2>: 让S[i]不匹配T[j],则问题就变为S[1:i-1]中的子串与T[1:j]相同的个数，则
F(i,j) = F(i-1,j)
故，S[i] = T[j]时，F(i,j) = F(i-1,j-1) + F(i-1,j)
当S[i] != T[j]:
问题退化为S[1:i-1]中的子串与T[1:j]相同的个数
故，S[i] != T[j]时，F(i,j) = F(i-1,j)
初始化：引入空串进行初始化
F(i,0) = 1 ---> S的子串与空串相同的个数，只有空串与空串相同
返回结果：
F(m,n)
*/

class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return int整型
     */
    int numDistinct(string S, string T) {
        // write code here
        int len1 = S.size();
        int len2 = T.size();
        vector<vector<int>> numD(len1 + 1,vector<int>(len2 + 1,0));
        // F(i,0) = 1;
        for(int i = 0; i <= len1; ++i) {
            numD[i][0] = 1;
        }
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <=len2; ++j) {
                if(S[i - 1] == T[j - 1])
                    numD[i][j] = numD[i - 1][j - 1] + numD[i - 1][j];
                else 
                    numD[i][j] = numD[i - 1][j];
            }
        }
        return numD[len1][len2];
    }
};