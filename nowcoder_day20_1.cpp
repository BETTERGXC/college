// 字符串翻转

#include<algorithm>
#include<iostream>
#include<string>

using namespace std;
int main() {
    string str;
    while(cin >> str) {
        reverse(str.begin(),str.end());
        cout << str << endl;
    }
}