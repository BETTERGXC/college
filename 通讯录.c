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
	info* data;                  // 结构体数组，存放通讯录中人的信息
	int size;					   // 当前有效元素个数
	int capacity;                // 当前空间大小
}Contact,*pContact;

void InitContact(pContact pc) {                // 初始化
	system("cls");
	pc->size = 0;
	pc->data = (info*)malloc(sizeof(info) * DEFAULT);
	pc->capacity = DEFAULT;
}

int CheckCapacity(pContact pc) {             // 检查空间是否够用，若不够用再申请
	if (pc->size == pc->capacity) {
		pc->data = (info*)realloc(pc->data,sizeof(info)*( pc->capacity + 10));
		if (pc->data == NULL) {
			return 0;
		}
		pc->capacity += 10;
	}
	return 1;
}

void AddContact(pContact pc) {             // 添加信息
	system("cls");
	info AddInfo;
	int judge = 1;
	printf("输入1继续输入，输入0结束输入\n");
	while (1) {
		if (CheckCapacity(pc) == 0) {
			printf("通讯录已满！添加失败\n");
			return;
		}
		printf("请输入姓名：\n");
		scanf("%s", AddInfo.name);
		printf("请输入电话：\n");
		scanf("%s", AddInfo.tele);
		printf("请输入地址：\n");
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
	printf("请输入要删除的人的姓名：\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("此人不存在！删除失败！\n");
		return;
	}
	for (int i = pos; i < pc->size-1; ++i) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("删除成功!\n");
}

void SearchContact(pContact pc) {
	system("cls");
	char name[NameMax];
	printf("请输入要查找的人！\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("此人不存在，查找失败！");
		return;
	}
	printf("+=================================================+\n");
	printf("|     姓名：%s                                                                \n", pc->data[pos].name);
	printf("|     电话：%s                                                                \n", pc->data[pos].tele);
	printf("|     地址：%s                                                                \n", pc->data[pos].addr);
	printf("+=================================================+\n");
	system("pause");
}

void ModifyContact(pContact pc) {
	system("cls");
	char name[NameMax];
	printf("请输入要修改的人的姓名：\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("此人不存在，修改失败！\n");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s",pc->data[pos].name);
	printf("请输入电话：\n");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址：\n");
	scanf("%s", pc->data[pos].addr);
	printf("修改成功！\n");
	
}

void ShowContact(pContact pc) {
	system("cls");
	for (int i = 0; i < pc->size; ++i) {
		printf("+======================第%d个人========================== +\n",i+1);
		printf("|     姓名：%s                                                                               \n", pc->data[i].name);
		printf("|     电话：%s                                                                               \n", pc->data[i].tele);
		printf("|     地址：%s                                                                               \n", pc->data[i].addr);
		printf("+========================================================= +\n");
	}
	system("pause");
}

void menu() {
	printf("\n\n\n\n\n\n\t\t\t\t\n");
	printf("\t\t\t\t\t========================\n");
	printf("\t\t\t\t\t\t1.增加信息                      \n");
	printf("\t\t\t\t\t\t2.删除信息                      \n");
	printf("\t\t\t\t\t\t3.修改信息                      \n");
	printf("\t\t\t\t\t\t4.查找信息                      \n");
	printf("\t\t\t\t\t\t5.显示信息                      \n");
	printf("\t\t\t\t\t\t0.退出程序                      \n");
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
	system("title  通讯录");
	fun();
}
