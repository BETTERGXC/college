 1. дһ���������ز����������� 1 �ĸ���
���磺 15 0000 1111 4 �� 1
����ԭ�ͣ�
int count_one_bits(unsigned int value)
{
	// ���� 1��λ�� 
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


������
while (n) {
	n = n & (n - 1);
	++num;
 }


 2. ���һ��������ÿһλ

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




 3. ��ȡһ�������������������е�ż��λ������λ�� 
�ֱ��������������

void PrintBit(int n) {
	//ż��λ
	for (int i = 31; i > 0; i -= 2) {
		printf("%d  ", (n >> i) & 1);
	}
	printf("\n");
	//����λ
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




 4. ���ʵ�֣�
����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
�������� :
1999 2299
������� : 7

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
