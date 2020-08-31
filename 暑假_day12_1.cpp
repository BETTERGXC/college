// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。
// 例如数组为{1，3，5，7，1，3，5，9}，找出7和9

#include<iostream>
#include<map>
using namespace std;

int main() {
	int arr[] = { 1,3,5,7,1,3,5,9 };
	map<int, int> m;

	for (int e : arr) {
		m[e]++;
	}

	for (auto e : m) {
		if (e.second == 1)
			cout << e.first << ' ';
	}

	cout << endl;
}
