// write your code here cpp 
// 养兔子
#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<long> v;
    int n;
    while(cin >> n) {
        v.resize(91);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        for(int i = 3;i <= 90;++i) {
            v[i] = v[i-1] + v[i-2];
        }
        cout << v[n] << endl;
        
    }
}