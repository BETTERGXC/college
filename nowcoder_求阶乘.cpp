
//https://www.nowcoder.com/practice/aa03dff18376454c9d2e359163bf44b8?tpId=117&tqId=37803&tab=answerKey 
class Solution {
public:
    long long thenumberof0(long long n) {
        long long count = 0;
        if(n < 5)
            return count;
        
        for(int i = 5; i <= n; i += 5) {
            int num = i;
            while(num % 5 == 0) {
                count++;
                num /= 5;
            }
        }
        return count;
    }
};
