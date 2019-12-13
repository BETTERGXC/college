#include"DLinkedList.h"


// 创建返回链表的头结点.
ListNode* ListCreate() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	return head;
}


// 双向链表销毁
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


// 双向链表打印
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


// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x) {
	ListNode* head = plist;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyNode(x);
	tail->_next = newnode;
	newnode->_next = head;
	newnode->_prev = tail;
	head->_prev = newnode;

}


// 双向链表尾删
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


// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x) {
	ListNode* newnode = BuyNode(x);
	ListNode* head = plist;
	ListNode* first = head->_next;
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = first;
	first->_prev = newnode;
}


// 双向链表头删
void ListPopFront(ListNode* plist) {
	ListNode* head = plist;
	ListNode* first = head->_next;
	ListNode* second = first->_next;
	free(first);
	head->_next = second;
	second->_prev = head;
}


// 双向链表查找
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


// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyNode(x);
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}


// 双向链表删除pos位置的节点
void ListErase(ListNode* pos) {
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

