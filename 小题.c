

// ��������Ϸ
/************************************************/ 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//������
void Game() {
	int num, unknow;
	//�����������
	srand(time(0));
	//ȡһ��1-100֮��������
	unknow = rand() % 100 + 1;
	while (1)
	{
		printf("��������µ�����\n");
		scanf("%d", &num);
		if (num < unknow)
			printf("���ˣ�\n");
		if (num > unknow)
			printf("���ˣ�\n");
		if (num == unknow) {
			printf("��ϲ�㣡�¶��ˣ�\n");
			break;
	}
	}
 
}
 
int main() {
	
	int choice = 0;
	while (1) {
		printf("=======================\n");
		printf("1.��ʼ��Ϸ\n");
		printf("0.������Ϸ\n");
		printf("=======================\n");
		scanf("%d", &choice);
		if (choice == 1)
			Game();
		else if (choice == 0)
			break;
		else
			printf("���������������������룡\n");
		
	}
	system("pause");
	return 0;
}





/*************************************************/


//���ַ������� 


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int find(int arr[], int size,int to_Find) {
	int left, right, mid;
	left = 0;
	right = size - 1;
	mid = left + right / 2;
	while(left <= right) {
		mid = left + right / 2;
		if (to_Find<arr[mid]) {
			//������
			right = mid-1;
		}
		if (to_Find > arr[mid]) {
			//������
			left =mid + 1;
		}
		if (to_Find == arr[mid]) {
			//�ҵ���
			return mid;
		}
	}
	return -1;
 
}
int main() {
	int size;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	size = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n",find(arr, size,10));
	system("pause");
	return 0;
}



/************************************************/

//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���,�������
//�����������룬����������Ρ����ξ�������ʾ�˳����� 

define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
//.��д����ģ��������������ĳ����� 
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����
 
int main() {
	char password[10];
	int count = 0;
	for (int index = 0; index < 3; index++) {
		printf("���������룺(��ס��ֻ�����λ���Ŷ)\n");
		scanf("%s", password);
		if (strcmp("wasd123.", password) == 0) {
			printf("������ȷ����ӭ����\n");
			break;
		}
		else {
			printf("����������������룡\n");
			count++;
		}
	}
	if (count == 3) {
		printf("���Ѿ�������Σ������˳�����\n");
	}
	system("pause");
	return 0;
}


/************************************************/

//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ���� 



#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
int main() {
	while (1)
	{
		char ch;
		ch = getchar();
		if (ch >= 'a' && ch <= 'z')
			printf("%c\n", ch - 32);
		if (ch >= 'A'&&ch <= 'Z')
			printf("%c\n", ch + 32);
	}
	system("pause");
	return 0;
}

