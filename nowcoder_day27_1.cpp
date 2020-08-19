// 不使用加减乘除做加法

class Solution {
public:
    // 二进制异或运算相当于对应位相加
    // 二进制与运算相当于对应为相加之后的进位
    // 把异或的结果和与的结果相加便是结果
    int Add(int num1, int num2)
    {
        int sum = 0;
        int carry = 0;
        while(num2)
        {
            sum = num1^num2;  
            carry = (num1&num2)<<1;  
            num1 = sum;
            num2 = carry;
        }
        // 这里要return num1，为了防止num2为0的情况，没有进行相加直接返回0
        return num1;
    }
};