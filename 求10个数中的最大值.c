#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[10];
	printf("ÇëÊäÈë 10 ¸öÊı×Ö£º\n");
	int i = 0, max = 0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	max = a[0];
	for (i = 0; i < 10; i++) {
		if (a[i] > a[i + 1]) {
			max = a[i];
		}
		else
			max = a[i + 1];
 
	}
	printf("max = %d\n", max);
	system("pause");
	return 0;
}


