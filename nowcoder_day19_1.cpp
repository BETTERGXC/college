// 汽水瓶

#include<iostream>
#include<string>
using namespace std;

int bottol(int num) {
    int sum = 0;
    while (num) {
        if (num % 3 == 0) {
            sum += num / 3;
            num = num / 3;
        }
        else if (num % 3 == 2) {
            sum += num / 3;
            num = num % 3 + num / 3;

        }
        else if (num < 2) {
            num = 0;
        }
        if(num == 2){
            sum += 1;
            num = 0;
        }
        else {
            sum += num / 3;
            num = num / 3 + num % 3;
        }
    }
    return sum;

}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0)
            continue;
        cout << bottol(n) << ' ';
        cout << n / 2 << endl;
    }
}




//  简便算法

#include<iostream>
int main() {
    int n;
    while(cin >> n) {
        cout << n/2 << endl;
    }
    return 0;
}