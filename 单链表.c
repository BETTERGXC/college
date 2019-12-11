#include"SLinkedList.h"


SListNode* BuySListNode(SLTDateType x) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

// 单链表打印
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

// 单链表尾插
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

// 单链表的尾删
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

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x) {
	SListNode* cur = BuySListNode(x);
	SListNode* head = *pplist;
	cur->next = head->next;
	head->next = cur;
}

// 单链表头删
void SListPopFront(SListNode** pplist) {
	SListNode* cur = *pplist;
	SListNode* next = cur->next;
	free(cur);
	*pplist = next;
	next = NULL;
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	int count = 0;
	int judge = 0;
	while (plist != NULL) {
		count++;
		if (plist->data == x) {
			printf("所查找值在链表的第%d个结点\n",count);
			judge = 1;
		}
		plist = plist->next;
	}
	if (judge == 0) {
		printf("链表中查无该值\n");
	}

}

// 单链表在第 i 个结点位置之后插入x
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

// 单链表删除第 i 个结点位置之后的值

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

//// 单链表的销毁
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

