// 模拟实现函数 pow(x,y) , 即实现运算x^y(x的y次方), 这里x和y都为整数

#include<iostream>
#include<string>
using namespace std;

int Pow(int x, int y) {
	int ret = 0;
	y = y - 1;
	while (y--) {
		ret += x * x;
	}
	return ret;
}

int main() {
	cout << Pow(3, 2) << endl;
}