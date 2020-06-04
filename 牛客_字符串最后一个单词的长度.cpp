#include<iostream>
using namespace std;
int main() {
    string str;
    while(getline(cin,str)) {
        int count = 0;
        int i = 0;
        while(str[i] != '\0') {
            count++;
            if(str[i] == ' ')
                count = 0;
            ++i;
        }
        cout << count;
    }
    
}
