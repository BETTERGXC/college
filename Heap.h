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
//���µ���
void AdjustDown(int *a, int n, int root);
//���ϵ���
void AdjustUp(int* a,int child);
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// ��������ж�����
void HeapSort(int* a, int n);
//Top K
void PrintTopK(int* a, int n, int k);
