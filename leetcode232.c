typedef int DataType;   /*定义栈中数据元素的数据类型*/

typedef struct node {
	DataType *data;  
	int capacity;   // 栈的容量
	int top;          // 栈顶
}sqstack; 


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


/*************************************************************************************************/

typedef struct {
    sqstack* pushst;
    sqstack* popst;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->pushst=creat();
    q->popst = creat();
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    Push(obj->pushst,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(IsEmpty(obj->popst)){
        while(!IsEmpty(obj->pushst)){
            Push(obj->popst,Pop(obj->pushst));
        }
    }
    int front = Pop(obj->popst);
    return front;
    
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(IsEmpty(obj->popst)){
        while(!IsEmpty(obj->pushst)){
            Push(obj->popst,Pop(obj->pushst));
        }
    }
    return Top(obj->popst);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return IsEmpty(obj->pushst)&&IsEmpty(obj->popst);
}

void myQueueFree(MyQueue* obj) {
    Free(obj->pushst);
    Free(obj->popst);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
