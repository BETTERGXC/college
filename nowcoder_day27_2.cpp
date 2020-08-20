// 三角形

#include<iostream>
using namespace std;

int main() {
    // 范围比较大，类型使用double
    double a;
    double b;
    double c;
    
    while(cin >> a >> b >> c) {
        int flag = 0;
        if(a+b > c) {
            if(b+c > a) {
                if(a+c > b) {
                    cout << "Yes" << endl;
                    flag = 1;
                }
            }
        }
        if(flag == 0) {
            cout << "No" << endl;
        }
    }
}