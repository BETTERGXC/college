#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define NameMax 100
#define TeleMax 12
#define AddressMax 200
#define DEFAULT 10

typedef struct info {
	char name[NameMax];
	char tele[TeleMax];
	char addr[AddressMax];
}info;

typedef struct Contact {
	info* data;                  // �ṹ�����飬���ͨѶ¼���˵���Ϣ
	int size;					   // ��ǰ��ЧԪ�ظ���
	int capacity;                // ��ǰ�ռ��С
}Contact,*pContact;

void InitContact(pContact pc) {                // ��ʼ��
	system("cls");
	pc->size = 0;
	pc->data = (info*)malloc(sizeof(info) * DEFAULT);
	pc->capacity = DEFAULT;
}

int CheckCapacity(pContact pc) {             // ���ռ��Ƿ��ã���������������
	if (pc->size == pc->capacity) {
		pc->data = (info*)realloc(pc->data,sizeof(info)*( pc->capacity + 10));
		if (pc->data == NULL) {
			return 0;
		}
		pc->capacity += 10;
	}
	return 1;
}

void AddContact(pContact pc) {             // �����Ϣ
	system("cls");
	info AddInfo;
	int judge = 1;
	printf("����1�������룬����0��������\n");
	while (1) {
		if (CheckCapacity(pc) == 0) {
			printf("ͨѶ¼���������ʧ��\n");
			return;
		}
		printf("������������\n");
		scanf("%s", AddInfo.name);
		printf("������绰��\n");
		scanf("%s", AddInfo.tele);
		printf("�������ַ��\n");
		scanf("%s", AddInfo.addr);
		pc->data[pc->size] = AddInfo;
		pc->size++;
		scanf("%d", &judge);
		if (judge == 0) {
			break;
		}
	}
	
	
		
}

int FindContact(pContact pc,char* name) {
	for (int i = 0; i < pc->size; ++i) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

void DelContact(pContact pc) {
	system("cls");
	char name[NameMax];
	printf("������Ҫɾ�����˵�������\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("���˲����ڣ�ɾ��ʧ�ܣ�\n");
		return;
	}
	for (int i = pos; i < pc->size-1; ++i) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("ɾ���ɹ�!\n");
}

void SearchContact(pContact pc) {
	system("cls");
	char name[NameMax];
	printf("������Ҫ���ҵ��ˣ�\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("���˲����ڣ�����ʧ�ܣ�");
		return;
	}
	printf("+=================================================+\n");
	printf("|     ������%s                                                                \n", pc->data[pos].name);
	printf("|     �绰��%s                                                                \n", pc->data[pos].tele);
	printf("|     ��ַ��%s                                                                \n", pc->data[pos].addr);
	printf("+=================================================+\n");
	system("pause");
}

void ModifyContact(pContact pc) {
	system("cls");
	char name[NameMax];
	printf("������Ҫ�޸ĵ��˵�������\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("���˲����ڣ��޸�ʧ�ܣ�\n");
		return;
	}
	printf("������������\n");
	scanf("%s",pc->data[pos].name);
	printf("������绰��\n");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ��\n");
	scanf("%s", pc->data[pos].addr);
	printf("�޸ĳɹ���\n");
	
}

void ShowContact(pContact pc) {
	system("cls");
	for (int i = 0; i < pc->size; ++i) {
		printf("+======================��%d����========================== +\n",i+1);
		printf("|     ������%s                                                                               \n", pc->data[i].name);
		printf("|     �绰��%s                                                                               \n", pc->data[i].tele);
		printf("|     ��ַ��%s                                                                               \n", pc->data[i].addr);
		printf("+========================================================= +\n");
	}
	system("pause");
}

void menu() {
	printf("\n\n\n\n\n\n\t\t\t\t\n");
	printf("\t\t\t\t\t========================\n");
	printf("\t\t\t\t\t\t1.������Ϣ                      \n");
	printf("\t\t\t\t\t\t2.ɾ����Ϣ                      \n");
	printf("\t\t\t\t\t\t3.�޸���Ϣ                      \n");
	printf("\t\t\t\t\t\t4.������Ϣ                      \n");
	printf("\t\t\t\t\t\t5.��ʾ��Ϣ                      \n");
	printf("\t\t\t\t\t\t0.�˳�����                      \n");
	printf("\t\t\t\t\t========================\n");
}

void fun() {
	Contact pc;
	InitContact(&pc);
	while (1) {
		system("cls");
		menu();
		int choice;
		scanf("%d",&choice);
		switch (choice) {
			case 1:AddContact(&pc); break;
			case 2:DelContact(&pc); break;
			case 3:ModifyContact(&pc); break;
			case 4:SearchContact(&pc); break;
			case 5:ShowContact(&pc); break;
			case 0:return;
		}
	}
}

int main() {
	system("title  ͨѶ¼");
	fun();
}
