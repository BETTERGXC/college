// 读取一个字符串，输出字符串中最大的连续数字串




#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    vector<char> v1;
    vector<char> v2;
    for (int i = 0; i < str.size(); ++i) {
        while (i < str.size() && (str[i] <'0' || str[i] > '9')) {
            ++i;
        }
        int pos = 0;
        while (i < str.size() && (str[i] >= '0' && str[i] <= '9')) {
            if (str[i] + 1 == str[i + 1]) {
                v1.push_back(str[i]);
            }
            
            ++i;
        }
        v1.push_back(str[i - 1]);
        if (v1.size() > v2.size()) {
            v2.resize(0);
            for (int j = 0; j < v1.size(); ++j) {
                v2.push_back(v1[j]);
            }
        }
        v1.resize(0);
        
   }
    vector<char>::iterator it = v2.begin();
    while (it != v2.end()) {
        cout << *it;
        ++it;
    }
    cout << endl;

}