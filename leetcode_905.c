//����ż�������� 



//����һ���Ǹ��������� A������һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ�ء�
//
//����Է���������������κ�������Ϊ�𰸡�
//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int left = 0;
	int right = ASize - 1;
	int arr[ASize];
	for (int i = 0; i < ASize; ++i) {
		if (A[i] % 2 == 0) {
			arr[left] = A[i];
			++left;
		}
		else {
			arr[right] = A[i];
			--right;
		}
	}
	for (int i = 0; i < ASize; ++i) {
		A[i] = arr[i];
	}
	*returnSize = ASize;
	return A;
}
