#include"DLinkedList.h"


// �������������ͷ���.
ListNode* ListCreate() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	return head;
}


// ˫����������
void ListDestory(ListNode* plist) {
	ListNode* first = plist->_next;
	ListNode* second = first->_next;
	while (plist->_next != plist)
	{
		plist->_next = second;
		free(first);
		first = second;
		second = second->_next;
	}
	free(plist);
}


// ˫�������ӡ
void ListPrint(ListNode* plist) {
	ListNode* head = plist;
	ListNode* first = head->_next;
	while (first != head) {
		printf("%d   ", first->_data);
		first = first->_next;
	}
	printf("\n");
}


ListNode* BuyNode(LTDataType x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}


// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x) {
	ListNode* head = plist;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyNode(x);
	tail->_next = newnode;
	newnode->_next = head;
	newnode->_prev = tail;
	head->_prev = newnode;

}


// ˫������βɾ
void ListPopBack(ListNode* plist) {
	ListNode* head = plist;
	ListNode* tail = head->_prev;
	ListNode* newTail = tail->_prev;
	if (head != tail) {
		head->_prev = newTail;
		newTail->_next = head;
		free(tail);
	}
}


// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x) {
	ListNode* newnode = BuyNode(x);
	ListNode* head = plist;
	ListNode* first = head->_next;
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = first;
	first->_prev = newnode;
}


// ˫������ͷɾ
void ListPopFront(ListNode* plist) {
	ListNode* head = plist;
	ListNode* first = head->_next;
	ListNode* second = first->_next;
	free(first);
	head->_next = second;
	second->_prev = head;
}


// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x) {
	ListNode* first = plist->_next;
	while (first != plist) {
		if (first->_data == x) {
			return first;
		}
		first = first->_next;
	}
	return NULL;
}


// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyNode(x);
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}


// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

