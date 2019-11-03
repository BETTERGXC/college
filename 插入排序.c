
void sort(int a[],int length) {
	int key;
	int i;
	for (int j = 1; j < length;j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
}

int main() {
	int a[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}
	int length = sizeof(a) / sizeof(int);
	sort(a,length);
	for (int i = 0; i < 5; i++) {
		printf("%d  ",a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
