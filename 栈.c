#include"Stack.h"

// ����ջ
sqstack* creat() {
	sqstack* stack;
	stack = (sqstack*)malloc(sizeof(sqstack));
	if (stack == NULL) {
		printf(" malloc failed \n");
	}
	stack->data = (DataType*)malloc(10*sizeof(DataType));    //��ʼ������Ϊ 10
	if (stack->data == NULL) {
		printf(" malloc failed \n");
	}
	stack->top = -1;
	stack->capacity = 10;
	return stack;
}


//�ж�ջ�Ƿ�Ϊ�գ�0��ʾ�ǿգ�1��ʾ�գ�
int IsEmpty(sqstack* s) {
	if (s->top == -1)
		return 1;
	return 0;
}


//�ж�ջ�Ƿ�Ϊ����0��ʾ������1��ʾ����
int IsFull(sqstack* s) {
	if (s->capacity == s->top)
		return 1;
	return 0;
}


//���ջ
void Clear(sqstack* s) {
	s->top = -1;
}


//��ջ
void Push(sqstack* s, DataType value) {
	if (!IsFull(s)) {
		s->data[s->top+1] = value;
		s->top++;
	}
	else
	{
		s->data = (DataType*)realloc(s,2*s->capacity*sizeof(DataType));
		s->data[s->top+1] = value;
		s->top++;
		s->capacity = 2 * s->capacity;
	}
}


//��ջ
DataType Pop(sqstack* s) {
	s->top--;
	return s->data[s->top + 1];
}


// ��ȡջ��������
DataType Top(sqstack* s) {
	return s->data[s->top];
}


//�ͷ�ջ
void Free(sqstack *s) {
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
}

