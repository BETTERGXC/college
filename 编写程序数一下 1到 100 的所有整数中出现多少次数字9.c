//��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9


int main() {
	int x, y, i, count = 0;
	for (i = 1; i <= 100; i++) {
		x = i % 10;
		y = i / 10;
		if (x == 9 || y == 9) {
			count++;
			if (x == 9 && y == 9)
				count++;
		}
			
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
