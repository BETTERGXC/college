#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
//向下调整
void AdjustDown(int *a, int n, int root);
//向上调整
void AdjustUp(int* a,int child);
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
// 对数组进行堆排序
void HeapSort(int* a, int n);
//Top K
void PrintTopK(int* a, int n, int k);
