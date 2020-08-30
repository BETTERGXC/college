// 因子个数
// write your code here cpp
// 从最小因子2到数字的最大因子数（数字的平方根）开始判断是否能够取余
// 可以则循环取余直到取余不为0，因子个数 + 1；否则使用下一个因子计算
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int ret = 0;
        for (int i = 2; i < sqrt(n); ++i) {
            if ((n % i) == 0) {
                while ((n % i) == 0) {
                    n = n / i;
                }
                ret++;
            }
        }
        // 最终整除了各个因子数之后剩余的数字不为1则本身也是一个因子，因此因子数+1
        if (n != 1)
            ret++;
        cout << ret << endl;
    }
}