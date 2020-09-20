class Solution {
public
    
      找缺失数字
      @param a int整型一维数组 给定的数字串
      @param aLen int a数组长度
      @return int整型
     
    int solve(int a, int aLen) {
         write code here
        
        for(int i = 0; i  aLen; ++i) {
            if(a[i] !=  i) 
                return i;
        }
        return -1;
        
        int res = aLen;
        for(int i = 0; i  aLen; ++i) {
            res ^= i ^ a[i];
        }
        return res;
    }
};