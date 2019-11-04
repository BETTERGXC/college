/*
��д������
unsigned int reverse_bit(unsigned int value);
��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��

�磺
��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001
��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�
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
��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
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

/*���ʵ�֣�
һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
���ҳ�������֡���ʹ��λ���㣩*/
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


/*��һ���ַ����������Ϊ:"student a am i",
���㽫��������ݸ�Ϊ"i am a student".
Ҫ��
����ʹ�ÿ⺯����
ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

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
	//������ת
	reverse_str(str, str + len - 1);
	//�ֲ���ת
	while(*cur){
		char* start = cur;
		while (*cur != ' '&&*cur != '\0')
			++cur;
		//��ת��ǰ����
		reverse_str(start, cur - 1);
		//�ߵ���һ�����ʵ���ʼλ��
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
