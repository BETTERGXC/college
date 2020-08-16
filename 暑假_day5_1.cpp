// 有一张单链表，编写函数求倒数第K个结点

#include<iostream>
using namespace std;

typedef struct List
{
	int data;
	struct List* next;
}List;

List* return_countdown_knode() {
	List head;
	int k = 0;
	cin >> k;
	int count = k;
	List *p = head.next;
	List* q = NULL;
	while (p) {
		p = p->next;
		if (count) {
			count--;
		}
		if (count == 0) {
			q = head.next;
		}
		if (q) {
			q = q->next;
		}
	}
	return q;

}