// 输入一个整数，输出二进制有几位是1


#include<iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		while (n) {
			if ((n & 0x1) == 1) {
				count++;
			}
			n = n >> 1;
		}
		cout << count << endl;
	}
}