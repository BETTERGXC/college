//有序数组的平方 

//给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。


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


    //   冒泡排序会超时
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
