//���������ƽ�� 

//����һ�����ǵݼ�˳��������������� A������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int* sortedSquares(int* A, int ASize, int* returnSize){
    int* arr = (int*)malloc(ASize*sizeof(int));
    for(int i = 0;i<ASize;++i) {
        arr[i] = A[i] * A[i];
    }


    //   ð������ᳬʱ
    // for(int i = 0;i<ASize-1;++i) {
    //     for(int j = 0;j<ASize-i-1;++j) {
    //         if(arr[j]>arr[j + 1]) {
    //             int tmp;
    //             tmp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = tmp;
    //         }
    //     }
    // }

    qsort (arr, ASize, sizeof(int), compare);
    *returnSize = ASize;
    return arr;
}
