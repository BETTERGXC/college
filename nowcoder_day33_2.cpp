// write your code here cpp
// 客似云来
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<long> v;
    v.resize(81);
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    for(int i = 3;i<81;++i) {
        v[i] = v[i-1] + v[i-2];
    }
    
    int from,to;
    while(cin >> from >> to) {

        long sum = 0;
        for(int i = from;i<=to;++i) {
            sum += v[i];
        }
    
        cout << sum << endl;
    }
}