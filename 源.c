#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//创建一个数组
//实现函数 init （）初始化数组
//实现 empty （）清空数组
//实现 revers（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
void initialize(int arr[],int size) {   
	//初始化数组
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	printf("初始化完的数组为：\n");
	for (int i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
}

void reverse(int arr[],int size) {
	//实现数组的逆置
	//int b[sizeof(arr) / sizeof(arr[0])];
	int b[10];
	for (int i = 0; i < size; i++) {
		b[i] = arr[i];
	}
	printf("转置完的数组为:\n");
	for (int i = 0,j = size - 1; i < size; i++,j--) {
		arr[i] = b[j];
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
}

void empty(int arr[],int size) {
	printf("清空后的数组为：\n");
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
		printf("%d\t", arr[i]);
	}
	system("pause");
	printf("\n");
}
int main() {
	int a[10];
	int size = sizeof(a) / sizeof(a[0]);
	initialize(a,size);
	reverse(a, size);
	empty(a, size);
	return 0;
}