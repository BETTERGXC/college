#include"SLinkedList.h"


SListNode* BuySListNode(SLTDateType x) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

// �������ӡ
void SListPrint(SListNode* plist) {
	SListNode* cur = plist;
	if (cur == NULL) {
		printf("NULL\n");
	}
	else {
		while (cur != NULL) {
			printf("%d -->", cur->data);
			cur = cur->next;
		}
		printf("NULL\n");
	}
	
}

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x) {
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL) {
		*pplist = newnode;
	}
	else {
		SListNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

// �������βɾ
void SListPopBack(SListNode** pplist) {
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		if (prev != NULL)
			prev->next = NULL;
	}

}

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x) {
	SListNode* cur = BuySListNode(x);
	SListNode* head = *pplist;
	cur->next = head->next;
	head->next = cur;
}

// ������ͷɾ
void SListPopFront(SListNode** pplist) {
	SListNode* cur = *pplist;
	SListNode* next = cur->next;
	free(cur);
	*pplist = next;
	next = NULL;
}

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	int count = 0;
	int judge = 0;
	while (plist != NULL) {
		count++;
		if (plist->data == x) {
			printf("������ֵ������ĵ�%d�����\n",count);
			judge = 1;
		}
		plist = plist->next;
	}
	if (judge == 0) {
		printf("�����в��޸�ֵ\n");
	}

}

// �������ڵ� i �����λ��֮�����x
void SListInsertAfter(SListNode** pplist, int i,SLTDateType x) {
	SListNode* cur = *pplist;
	SListNode* newnode = BuySListNode(x);
	while (i) {
		cur = cur->next;
		i--;
	}
	newnode->next = cur->next;
	cur->next = newnode;
}

// ������ɾ���� i �����λ��֮���ֵ

void SListEraseAfter(SListNode* plist,int i) {
	SListNode* cur = plist;
	SListNode* next;
	while (i) {
		cur = cur->next;
		i--;
	}
	next = cur->next;
	cur->next = next->next;
	free(next);
	next = NULL;
}

//// �����������
void SListDestory(SListNode** pplist) {
	SListNode* head = *pplist;
	SListNode* delete;
	while (head) {
		delete = head;
		head = head->next;
		free(delete);
		delete = NULL;
	}
	*pplist = NULL;
}

