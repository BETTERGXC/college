// https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=117&tqId=37767&tab=answerKey 


class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if(n < 1 || m < 1)
            return -1;
        vector<int> vec(n, 0);
        int count = n;
        int i = -1;
        int step = 0;
        while(count > 0) {
            i++;
            if(i >= n)
                i = 0;
            if(vec[i] == -1) {
                continue;
            }
            step++;
            if(step == m) {
                vec[i] = -1;
                step = 0;
                count--;
            }
        }
        return i;
    }
};
