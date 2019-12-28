#include"Stack.h"

// 创建栈
sqstack* creat() {
	sqstack* stack;
	stack = (sqstack*)malloc(sizeof(sqstack));
	if (stack == NULL) {
		printf(" malloc failed \n");
	}
	stack->data = (DataType*)malloc(10*sizeof(DataType));    //初始化容量为 10
	if (stack->data == NULL) {
		printf(" malloc failed \n");
	}
	stack->top = -1;
	stack->capacity = 10;
	return stack;
}


//判断栈是否为空（0表示非空，1表示空）
int IsEmpty(sqstack* s) {
	if (s->top == -1)
		return 1;
	return 0;
}


//判断栈是否为满（0表示非满，1表示满）
int IsFull(sqstack* s) {
	if (s->capacity == s->top)
		return 1;
	return 0;
}


//清空栈
void Clear(sqstack* s) {
	s->top = -1;
}


//入栈
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


//出栈
DataType Pop(sqstack* s) {
	s->top--;
	return s->data[s->top + 1];
}


// 获取栈顶的数据
DataType Top(sqstack* s) {
	return s->data[s->top];
}


//释放栈
void Free(sqstack *s) {
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
}

