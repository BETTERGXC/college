#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//����һ������
//ʵ�ֺ��� init ������ʼ������
//ʵ�� empty �����������
//ʵ�� revers���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
void initialize(int arr[],int size) {   
	//��ʼ������
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	printf("��ʼ���������Ϊ��\n");
	for (int i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
}

void reverse(int arr[],int size) {
	//ʵ�����������
	//int b[sizeof(arr) / sizeof(arr[0])];
	int b[10];
	for (int i = 0; i < size; i++) {
		b[i] = arr[i];
	}
	printf("ת���������Ϊ:\n");
	for (int i = 0,j = size - 1; i < size; i++,j--) {
		arr[i] = b[j];
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
}

void empty(int arr[],int size) {
	printf("��պ������Ϊ��\n");
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