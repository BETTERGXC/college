class Solution {
public:

    // 等差数列求和
    /*
    int sumNums(int n) {
        return (int)(pow(n, 2) + n) >> 1;
    }
    */

    // 使用递归，但是如何让去执行递归语句？用到 &&，如果第一个表达式为真，还需要判断后边的表达式
    // 如果前边的为 0 了， 则不执行后边的语句
    int sumNums(int n) {
        n && (n = (sumNums(n - 1) + n));
        return n;
    }
};