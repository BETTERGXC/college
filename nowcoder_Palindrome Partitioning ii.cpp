// 状态F(i):字符前i个字符的最小分割次数
// 转移方程: F(i): j < i && [j + 1,i]是回文串 min{F(j) + 1}
// 如果整体为回文串 [1,i]: F(i) = 0
// 初始状态: F(i) = i - 1
// 返回: F(n)

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    
    bool isPal(string& s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
    
    int minCut(string s) {
        // write code here
        vector<int> minC(s.size() + 1);
        // 初始化 F(i) = i - 1;
        for(int i = 1; i <= s.size(); ++i) {
            minC[i] = i - 1;
        }
        for(int i = 1; i <= s.size(); ++i) {
            // 判断整体
            if(isPal(s,0,i - 1)) {
                minC[i] = 0;
                continue;
            }
            for(int j = 1; j < i; ++j) {
                // j < i && [j + 1,i]
                if(isPal(s,j,i - 1)) {
                    minC[i] = min(minC[i],minC[j] + 1);
                }
            }
        }
        return minC[s.size()];
    }
};