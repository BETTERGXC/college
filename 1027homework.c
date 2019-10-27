 1. 写一个函数返回参数二进制中 1 的个数
比如： 15 0000 1111 4 个 1
程序原型：
int count_one_bits(unsigned int value)
{
	// 返回 1的位数 
}

#include<stdio.h>
int count_one_bits( int value) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if ((value>>i & 0x1) == 1) {
			count++;
		}
	}
	return count;
}

int main() {
	int value;
	scanf("%d", &value);
	int ret = count_one_bits(value);
	printf("%d\n", ret);
	system("pause");
	return 0;
}


方法二
while (n) {
	n = n & (n - 1);
	++num;
 }


 2. 输出一个整数的每一位

void fuc(int n) {
	if (n > 9) {
		fuc(n / 10);
	}
	printf("%d    ", n % 10);
}

int main() {
	int n;
	scanf("%d", &n);
	fuc(n);
	printf("\n");
	system("pause");
	return 0;
}




 3. 获取一个数二进制序列中所有的偶数位和奇数位， 
分别输出二进制序列

void PrintBit(int n) {
	//偶数位
	for (int i = 31; i > 0; i -= 2) {
		printf("%d  ", (n >> i) & 1);
	}
	printf("\n");
	//奇数位
	for (int i = 30; i >= 0; i -= 2) {
		printf("%d  ", (n >> i) & 1);
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);
	PrintBit(n);
	system("pause");
	return 0;
}




 4. 编程实现：
两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
输入例子 :
1999 2299
输出例子 : 7

int BitDiffirent(int m,int n) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (((m >> i) & 1) != ((n >> i) & 1)) {
			++count;
		}
	}
	return count;
}

int main() {
	int m, n;
	scanf("%d %d",&m,&n);
	int ret = BitDiffirent(m, n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
