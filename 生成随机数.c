#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
int main() {
	system("title �����������");
	system("color f0");
	srand(time(NULL));
	int min,max,num;
	printf("��������Ҫ���ɵ����������Сֵ\n");
	scanf("%d",&min);
	printf("��������Ҫ���ɵ�����������ֵ\n");
	scanf("%d", &max);
	printf("��������Ҫ���ɵ�������ĸ�����\n");
	scanf("%d",&num);
	int* arr;
	arr = (int)malloc(sizeof(int)*num);
	for (int i = 0; i < num; ++i ) {
		arr[i] = rand() % max + min;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j])
				--i;
		}
		if (arr[i] == 4 || arr[i] == 31) {
			--i;
		}
	}
	printf("���ɵ������Ϊ��\n");
	for (int i = 0; i < num; i++) {
		printf("%d\t", arr[i]);
	}
	return 0;
}
