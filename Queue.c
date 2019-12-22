#include"Queue.h"


// ��ʼ������ 
void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_back = NULL;
}


// ��β����� 
void QueuePush(Queue* q, QDataType data) {
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_back == NULL) {
		q->_front = q->_back = newnode;
	}
	else
	{
		q->_back->_next = newnode;
		q->_back = q->_back->_next;
	}
}


// ��ͷ������ 
void QueuePop(Queue* q) {
	assert(q);
	if (q->_front->_next == NULL) {
		printf("%d  ",q->_front->_data);
		free(q->_front);
		q->_front = q->_back = NULL;
	}
	else
	{
		QueueNode* next = q->_front->_next;
		printf("%d  ",q->_front->_data);
		free(q->_front);
		q->_front = next;
	}
}


// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) {
	assert(q);
	return q->_front->_data;
}


// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q) {
	assert(q);
	return q->_back->_data;
}


// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q) {
	assert(q);
	QueueNode* cur = q->_front;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}


// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	return (q->_front == NULL) ? 1:0;
}


// ���ٶ��� 
void QueueDestroy(Queue* q) {
	assert(q);
	QueueNode* next;
	while (q->_front != q->_back)
	{
		next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
	free(q->_back);
	q->_front = NULL;
	q->_back = NULL;
}


