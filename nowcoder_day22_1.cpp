// 小易的升级之路


#include<iostream>
#include<vector>
using namespace std;

int func(int x,int y) {
    int max = 0;
    int less = x<y?x:y;
    for(int i = 1;i <= less;++i) {
        if(x % i == 0 && y % i == 0)
            max = i;
    }
    return max;
}

int main() {
    int n;
    int a;
    while(cin >> n >> a) {
        vector<int> v;
        v.resize(n);
        for(int i = 0;i < n;++i) {
            cin >> v[i];
        }
        for(int i = 0;i < n;++i) {
            if(a > v[i])
                a += v[i];
            else {
                a += func(a,v[i]);
            }
        }
        
        cout << a << endl;
    }
}