// 有一个数组 a , 编写函数，求数组中前K个最小的数字

#include<iostream>
#include<algorithm>
using namespace std;

int* KSmall(int* arr,int k,int n) {
	sort(arr,arr+n);
	int* ret = (int*)malloc(sizeof(int)*k);
	for (int i = 0; i < k; ++i) {
		ret[i] = arr[i];
	}
	return ret;
}
