// 求一个有序数组中两个元素值相加为k的数字，返回这两个元素的下标。
//要求时间复杂度是O(n),空间复杂度O(1)

#include<iostream>
#include<string>
using namespace std;

int* FindIndex(int* arr,int k,int size) {
	int* ret = (int*)malloc(sizeof(int) * 2);
	int left = 0;
	int right = size - 1;
	while (left < right) {
		if (arr[left] + arr[right] == k) {
			ret[0] = left;
			ret[1] = right;
			return ret;
		}
		else if (arr[left] + arr[right] < k ) {
			left++;
		}
		else {
			right--;
		}
	}
}