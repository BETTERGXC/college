#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
int main() {
	system("title 随机数生成器");
	system("color f0");
	srand(time(NULL));
	int min,max,num;
	printf("请输入你要生成的随机数的最小值\n");
	scanf("%d",&min);
	printf("请输入你要生成的随机数的最大值\n");
	scanf("%d", &max);
	printf("请输入你要生成的随机数的个数！\n");
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
	printf("生成的随机数为：\n");
	for (int i = 0; i < num; i++) {
		printf("%d\t", arr[i]);
	}
	return 0;
}
