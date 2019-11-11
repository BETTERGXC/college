#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>



调整数组使奇数全部都位于偶数前面。

题目：
输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。

void ReverseArr (int *arr,int sz) {
	int start = 0;
	int end = sz - 1;
	while (start < end) {
		while (start < end && arr[start] % 2 != 0)
			++start;
		while (start < end && arr[end] % 2 == 0)
			--end;
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		++start;
		--end;
	}
} 
int main() {

	int n;
	scanf("%d",&n);
	int* arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	ReverseArr(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}



杨氏矩阵
有一个二维数组.
数组的每行从左到右是递增的，每列从上到下是递增的.
在这样的数组中查找一个数字是否存在。
时间复杂度小于O(N);

数组：
1 2 3
2 3 4
3 4 5


1 3 4
2 4 5
4 5 6

1 2 3
4 5 6
7 8 9
void find(int** arr, int row, int col, int key, int* px, int* py) {
	从左下角开始查找（row - 1,0）
	int startx = row - 1;
	int starty = 0;

	while (startx >= 0 && starty < col) 
		if (arr[startx][starty] == key) {
			*px = startx;
			*py = starty;
			return;
		}
		else if (arr[startx][starty] > key) {
			--startx;
		}
		else {
			++starty;
		}
	*px = -1;
	*py = -1;
	return;
}

int main() {
	int row, col, key;
	int px = -1 , py = -1;
	printf("row col \n");
	scanf("%d %d",&row,&col);
	printf("input element\n");
	int** arr = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; ++i) {
		arr[i] = (int*)malloc(sizeof(int)*col);
		for (int j = 0; j < col; ++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	printf("key\n");
	scanf("%d",&key);
	find(arr, row, col, key, &px, &py);
	printf("%d %d\b",px,py);
	return 0;
}



实现一个函数，可以左旋字符串中的k个字符。
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB

void leftRotate(char  * arr, int k) {
	while (k--) {
		元素移动
		int start = 0;
		int tmp = arr[start];
		while (arr[start + 1] != '\0') {
			arr[start] = arr[start + 1];
			++start;
		}
		arr[start] = tmp;
	}
}

int main() {
	char arr[] = "ABCD";
	int k;
	scanf("%d",&k);
	printf("%s\n",arr);
	leftRotate(arr,k);
	printf("%s\n",arr);
	return 0;
}





判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.

AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC
void reverseString(char* left, char* right) {
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		++left;
		--right;
	}
}
void leftRotate(char* arr, int k) {
	int len = strlen(arr);
	k %= len;
	[0,k - 1]
	reverseString(arr, arr + k - 1);
	[k,len - 1]
	reverseString(arr + k, arr + len - 1);
	[0,len - 1]
	reverseString(arr, arr + len - 1);
}
int isRotate(char* dest, const char* src) {
	int len = strlen(dest);
	while (len--) {
		leftRotate(dest, 1);
		if (!strcmp(dest, src)) {
			printf("1\n");
			return 0;
		}
			
	}
	printf("0\n");
	return 0;
}

int main() {
	char dest[30];
	char src[30];
	scanf("%s",dest);
	scanf("%s",src);
	isRotate(dest,src);
	return 0;
}




一个数组中只有两个数字是出现一次，
其他所有数字都出现了两次。
找出这两个只出现一次的数字，编程实现。

void find(int* arr, int sz) {
	int ret = 0;
	int index = 0;
	for (int i = 0; i < sz; ++i) {
		ret ^= arr[i];
	}
	// ret: 两个单独出现的数字的异或结果
	// ret: 找到任意一个二进制为 1 的位置
	for (int i = 0; i < 32; ++i) {
		if (((ret >> i) & 1) == 1) {
			index = i;
			break;
		}
	}
	int num1 = 0, num2 = 0;
	for (int i = 0; i < sz; ++i) {
		// 通过 index 位的二进制值把数组分成两组，魅族中有一个数字单独出现一次
		if (((arr[i] >> index) & 1) == 1) 
			num1 ^= arr[i];
		else
			num2 ^= arr[i];
		

	}
	printf("%d  %d\n",num1,num2);
}

int main() {
	int n;
	scanf("%d",&n);
	int* arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	find(arr, n);
	return 0;
}

.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
给20元，可以多少汽水。
编程实现。
int main() {
	int n = 20;
	int totol = n;
	int empty = n;
	while (empty > 1) {
		totol += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n",totol);
	return 0;
}
