// 统计每个月兔子的总数

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int n;
    while(cin >> n) {
        if(n <= 4){
            cout << v[n] << endl;
            continue;
        }
        v.resize(n+1);
        for(int i = 5;i <= n;++i) {
            v[i] = v[i-1] + v[i - 2];
        }
        cout << v[n] << endl;
    }
}