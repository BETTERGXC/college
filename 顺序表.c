#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#define SLDataType int

typedef struct SeqList
{
	SLDataType* array; // 指向动态开辟的数组
	size_t size;    // 有效数据个数
	size_t capicity;  // 容量空间的大小
}SeqList;

// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SeqList* ps) {
	assert(ps);
	ps->array = NULL;
	ps->size = 0;
	ps->capicity = 0;
}
// 顺序表销毁
void SeqListDestory(SeqList* ps) {
	assert(ps);
	free(ps->array);
	ps->size = 0;
	ps->capicity = 0;
}
// 顺序表打印
void SeqListPrint(SeqList* ps) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* ps) {
	assert(ps);
	if (ps->size == ps->capicity) {
		size_t newcapacity = ps->capicity == 0 ? 4 : ps->capicity * 2;
		ps->array = (SLDataType*)realloc(ps->array, newcapacity * sizeof(SLDataType));
		ps->capicity = newcapacity;
	}
}
// 顺序表尾插
void SeqListPushBack(SeqList* ps, SLDataType x) {
	assert(ps);
	CheckCapacity(ps);
	size_t i = 0;
	for (; i < ps->size; i++);
	if (ps->size == i) {
		CheckCapacity(ps);
		ps->array[i] = x;
		ps->size++;
	}

}
// 顺序表尾删
void SeqListPopBack(SeqList* ps) {
	assert(ps);
	ps->size--;
}
// 顺序表头插
void SeqListPushFront(SeqList* ps, SLDataType x) {
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->size + 1; i > 0; i--) {
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = x;
	ps->size++;
}
// 顺序表头删
void SeqListPopFront(SeqList* ps) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}
// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		if (ps->array[i] == x)
			return i;
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x) {
	assert(ps);
	CheckCapacity(ps);
	for (int i = 0; i < ps->size; i++) {
		if (i == pos) {
			for (int j = ps->size; j > pos; j--) {
				ps->array[j] = ps->array[j - 1];
			}
			ps->array[pos] = x;
		}
	}
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		if (i == pos) {
			for (int j = pos; j < ps->size; j++) {
				ps->array[j] = ps->array[j + 1];
			}
		}
	}
	ps->size--;
}
