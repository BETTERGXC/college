
// 第一个猴子得到（x+4）/ 5，剩余（x+4）*（4/5）个
// 第二个猴子分完后剩余（x+4）* (4/5)^2个
// 第三个猴子分完后剩余（x+4）* (4/5)^3个
// 依次类推，第n个猴子分完后剩余（x+4）*（4/5）^n


#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            continue;
        }
        long a = pow(5, n) - 4;
        long b = pow(4, n) + n - 4;
        cout << a << " " << b << endl;
    }
    return 0;
}