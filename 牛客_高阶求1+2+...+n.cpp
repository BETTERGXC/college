// 在构造函数中进行求和，建立对象数组，多次调用构造函数
// 每次先给 sum 和 i 置 0

class Sum {
public:
    Sum() {
        sum += i;
        ++i;
    }
    static int GetSum() {
        return sum;
    }
    static void InitSum() {
        sum = 0;
        i = 1;
    }
private:
    static int i;
    static int sum;
};
int Sum::i = 1;
int Sum::sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Sum::InitSum();
        Sum a[n];
        return Sum::GetSum();
    }
};
