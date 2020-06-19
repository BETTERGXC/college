//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

#include<iostream>
using namespace std;

int main() {
    string table("0123456789ABCDEF");
    string ret;
    int M,N;
    cin>>M>>N;
    int flag = 1;
    if(M < 0) {
        flag = 0;
        M = -M;
    }
    while(M) {
        ret += table[M%N];
        M = M/N;
    }
    
    if(flag == 0) {
        ret += '-';
    }
    
    string::reverse_iterator rit = ret.rbegin();
    while (rit != ret.rend()) {
        cout << *rit;
        ++rit;
    }
}