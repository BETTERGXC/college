// write your code here cpp
// 剪花布条
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    string t;
    while(cin >> s >> t) {
        int count = 0;
        int pos = 0;
        while((pos = s.find(t,pos)) != string::npos) {
            pos += t.size();
            count++;
        }
        
        cout << count << endl;
    }
}