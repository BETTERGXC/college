class Solution {
public:
// 尽可能分成三份
//最优： 3 。把绳子尽可能切为多个长度为 3 的片段，留下的最后一段绳子的长度可能为 0,1,2三种情况。
//次优： 2 。若最后一段绳子长度为 2 ；则保留，不再拆为 1+1
//最差： 1 。若最后一段绳子长度为 1 ；则应把一份 3+1 替换为 2 + 2，因为 2 * 2 > 3*1

    int cuttingRope(int n) {
        if(n <= 3)
            return n - 1; 

        int a = n / 3;
        int b = n % 3;
       
        int ret = 1;
        if(b == 0) {
            for(int i = 0; i < a; i++) {
                ret *= 3;
            }
        }

        if(b == 1) {
            for(int i = 0; i < a - 1; i++) {
                ret *= 3;
            }
            ret *= 4;
        }

        if(b == 2) {
            for(int i = 0; i < a; i++) {
                ret *= 3;
            }
            ret *= 2;
        }

        return ret;
    }
};