#include"Heap.h"

// ���µ���
void AdjustDown(int *a, int n, int root) {
	int parents = root;
	int child = 2 * parents + 1;
	while (child < n) {
		if (child + 1 < n && a[child + 1] < a[child]) {
			++child;
		}
		if (a[parents] > a[child]) {

			int temp;
			temp = a[parents];
			a[parents] = a[child];
			a[child] = temp;

			parents = child;
			child = 2 * parents + 1;
		}
		else
		{
			break;
		}
	}
}

// ���ϵ���
void AdjustUp(int *a, int child) {
	int parents = (child - 1) / 2;
	while (child > 0) {
		if (a[child] < a[parents]) {
			int tmp;
			tmp = a[parents];
			a[parents] = a[child];
			a[child] = tmp;

			child = parents;
			parents = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// �ѵĹ���
void HeapCreat(Heap* hp,HPDataType* a,size_t n) {
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memccpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;


	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(hp->_a, hp->_size, i);
	}
	return hp;
}

// �ѵ�����
void HeapDestory(Heap* hp) {
	hp->_capacity = 0;
	hp->_size = 0;
	free(hp->_a);
}

// ����
void HeapPush(Heap* hp, HPDataType x) {
	if (hp->_capacity == hp->_size) {
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(hp->_a,  sizeof(HPDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}

// ɾ��
void HeapPop(Heap *hp) {
	int tmp;
	tmp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;
	hp->_size--;
	AdjustDown(hp->_a,hp->_size,0);
}

// ��ȡ����ߵ�����
HPDataType HeapTop(Heap* hp) {
	return hp->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp) {
	return hp->_size;
}

// �ж��Ƿ�Ϊ��
int HeapEmpty(Heap* hp) {
	return hp->_size == 0 ? 1 : 0;
}

// ��������ж�����
void HeapSort(int *a, int n) {
	for (int root = (n - 1 - 1) / 2; root >= 0; --root) {
		AdjustDown(a, n, root);
	}
	int end = n - 1;
	while (end > 0) {
		int tmp;
		tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;
		AdjustDown(a, end, 0);

		--end;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d  ", a[i]);
	}
	printf("\n");
}

//Top k
void PrintTopK(int* a, int n, int k) {
	HeapSort(a, n);
	for (int i = 0; i < k; ++i) {
		printf("%d  ", a[i]);
	}
	printf("\n");
}
