//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

#include<iostream>
#include<string>
using namespace std;
int main() {
    int table[256] = {0};
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    string ret;
    for(int i = 0;i<s2.size();++i) {
        table[s2[i]]++;
    }
    for(int i = 0;i<s1.size();++i) {
        if(table[s1[i]] == 0){
            ret += s1[i];
        }
    }
    cout << ret;
}