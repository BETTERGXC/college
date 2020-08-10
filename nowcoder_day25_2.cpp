// 树根

#include<iostream>
#include<string>
using namespace std;

int RootNum(int num) {
    int nroot = 0;
    while(num > 0) {
        nroot += num % 10;
        num /= 10;
    }
    while(nroot > 9) {
        nroot = RootNum(nroot);
    }
    return nroot;
}

int main() {
    string str;
    while(cin >> str) {
        // 防止输入的数据过大
        int sum = 0;
        for(int i = 0; i < str.size();++i) {
            sum += str[i] - '0';
        }
        cout << RootNum(sum) << endl;
    }
    return 0;
}