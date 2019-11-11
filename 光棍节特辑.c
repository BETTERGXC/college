#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>



��������ʹ����ȫ����λ��ż��ǰ�档

��Ŀ��
����һ���������飬ʵ��һ��������
�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
����ż��λ������ĺ�벿�֡�

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



���Ͼ���
��һ����ά����.
�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
�������������в���һ�������Ƿ���ڡ�
ʱ�临�Ӷ�С��O(N);

���飺
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
	�����½ǿ�ʼ���ң�row - 1,0��
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



ʵ��һ�����������������ַ����е�k���ַ���
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB

void leftRotate(char  * arr, int k) {
	while (k--) {
		Ԫ���ƶ�
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





�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1
����s1=abcd��s2=ACBD������0.

AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA

AABCD����һ���ַ��õ�DAABC
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




һ��������ֻ�����������ǳ���һ�Σ�
�����������ֶ����������Ρ�
�ҳ�������ֻ����һ�ε����֣����ʵ�֡�

void find(int* arr, int sz) {
	int ret = 0;
	int index = 0;
	for (int i = 0; i < sz; ++i) {
		ret ^= arr[i];
	}
	// ret: �����������ֵ����ֵ������
	// ret: �ҵ�����һ��������Ϊ 1 ��λ��
	for (int i = 0; i < 32; ++i) {
		if (((ret >> i) & 1) == 1) {
			index = i;
			break;
		}
	}
	int num1 = 0, num2 = 0;
	for (int i = 0; i < sz; ++i) {
		// ͨ�� index λ�Ķ�����ֵ������ֳ����飬��������һ�����ֵ�������һ��
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

.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
��20Ԫ�����Զ�����ˮ��
���ʵ�֡�
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
