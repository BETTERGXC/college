
//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ 



int main() {
	float sum = 0.0;
	int i;
	for (i = 1; i <= 100; i++) {
		sum = sum + (pow(-1, i+1) * 1 / i);
	}
	printf("%f\n", sum);
	system("pause");
	return 0;


