//写一个函数求，求 unsigned int 型变量 x 在内存中二进制 1 的个数
#include<iostream>
using namespace std;

int main() {
	unsigned int x;
	cin >> x;
	int count = 0;
	while (x != 0) {
		if ((x & 0x1) == 1) {
			count++;
		}
		x = x >> 1;
	}
	cout << count << endl;
}