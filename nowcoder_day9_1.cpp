// 设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。

class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        
        while(B != 0) {
            int sum = A^B;
            int carry = (unsigned)(A&B)<<1;
            A = sum;
            B = carry;
        }
        return A;
    }
};