#include"Queue.h"


// 初始化队列 
void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_back = NULL;
}


// 队尾入队列 
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


// 队头出队列 
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


// 获取队列头部元素 
QDataType QueueFront(Queue* q) {
	assert(q);
	return q->_front->_data;
}


// 获取队列队尾元素 
QDataType QueueBack(Queue* q) {
	assert(q);
	return q->_back->_data;
}


// 获取队列中有效元素个数 
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


// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	return (q->_front == NULL) ? 1:0;
}


// 销毁队列 
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


