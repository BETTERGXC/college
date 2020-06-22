// 一个数组有 N 个元素，求连续子数组的最大和


#include<iostream>
#include<string>
using  namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int sum = 0;
	int max = arr[0];
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
		if (sum > max) {
			max = sum;
		}
		if(sum<0) {
			sum = 0;
		}
	}
	cout << max;
}