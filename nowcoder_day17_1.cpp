// 杨辉三角形变形




#include<iostream>
using namespace std;

int func(int cow,int row) {
    if(row == 1 || row == 2*cow-1)
        return 1;
    if(row < 1 || row > 2*cow-1)
        return 0;
    return func(cow-1,row-2) + func(cow-1,row-1) + func(cow-1,row);
}

int main() {
    int cow;
    while(cin >> cow) {
        for(int i = 1;i<=cow*2-1;++i) {
            if(func(cow,i) % 2 == 0) {
                cout << i << endl;;
                break;
            }
            else if(i == 2*cow-1)
                cout << -1;
        }
    }
}