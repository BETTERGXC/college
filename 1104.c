/*
编写函数：
unsigned int reverse_bit(unsigned int value);
这个函数的返回值是value的二进制位模式从左到右翻转后的值。

如：
在32位机器上25这个值包含下列各位：
00000000000000000000000000011001
翻转后：（2550136832）
10011000000000000000000000000000
程序结果返回：
2550136832

*/

unsigned int reverse_bit(unsigned int value) {
	unsigned int ret = 0;
	for (int i = 0; i < 32; i++) {
		ret += ((value >> i) & 1)*pow(2, 31 - i);
	}
	return ret;
}
int main() {
	unsigned int value;
	scanf("%u", &value);
	printf("%u\n", reverse_bit(value));
	system("pause");
	return 0;
}


/*
不使用（a+b）/2这种方式，求两个数的平均值。
*/

int avg(int a, int b) {
	return (a & b) +((a^b) >> 1);
}

int main() {
	int a;
	int b;
	scanf("%d %d", &a, &b);
	printf("%d\n", avg(a, b));
	system("pause");
	return 0;
}

/*编程实现：
一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
请找出这个数字。（使用位运算）*/
int main() {
	int* a;
	int num;
	scanf("%d", &num);
	printf("\n");
	a = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &a[i]);
	}
	printf("\n");
	int ret = a[0];
	for (int i = 1; i < num; i++) {
		ret ^= a[i];
	}
	printf("%d\n",ret);
	system("pause");
	return 0;
}


/*有一个字符数组的内容为:"student a am i",
请你将数组的内容改为"i am a student".
要求：
不能使用库函数。
只能开辟有限个空间（空间个数和字符串的长度无关）。

student a am i
i ma a tneduts
i am a student
*/

void reverse_str(char* start, char* end) {
	while (start < end) {
		char tmp = *start;
		*start = *end;
		*end = tmp;
		++start;
		--end;
	}
}
int Strlen(char* str) {
	int count = 0;
	while (*str++)
		++count;
	return count;
}
void reverse(char* str) {
	char* cur = str;
	int len = Strlen(str);
	//整体逆转
	reverse_str(str, str + len - 1);
	//局部逆转
	while(*cur){
		char* start = cur;
		while (*cur != ' '&&*cur != '\0')
			++cur;
		//逆转当前单词
		reverse_str(start, cur - 1);
		//走到下一个单词的起始位置
		while (*cur == ' ')
			++cur;
	}
}

int main() {
	char str[] = "student a am i";
	reverse(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}
