// 最难的问题

// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    char key[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
    string str;
    while(getline(cin,str)) {
        vector<char> v;
        for(int i = 0;i<str.size();++i) {
            if(str[i] != ' ') {
                v.push_back(key[str[i] - 'A']);
            }
            else {
                v.push_back(str[i]);
            }
        }
        
        for(auto& e :v ) {
            cout << e;
        }
        cout << endl;
    }
}