// 有假币

// write your code here cpp
#include<iostream>
using namespace std;

int main() {
    int num;
    while(cin >> num) {
        if(num == 0) 
            break;
        int count = 0;
        while(num >= 2) {
            if(num % 3) {
                num = num/3 + 1;
            }
            else {
                num /= 3;
            }
            count++;
        }
        cout << count << endl;
    }
}