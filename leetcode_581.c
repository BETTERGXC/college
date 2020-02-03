// 最短无序连续子数组 






// 先定义一个临时数组，用来将 nums 内的元素进行排序，然后从首尾进行比较，如果 start相等则++
// 如果 end相等则--，直到首尾元素都不相同，则从不相同的位置进行了排序。

// 用 qsort 排序防止超时
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int findUnsortedSubarray(int* nums, int numsSize){
    int tmp[numsSize];
    for(int i = 0;i<numsSize;++i) {
        tmp[i] = nums[i];
    }
    qsort (tmp, numsSize, sizeof(int), compare);
    int start = 0;
    int end = numsSize - 1;
    while(start<end) {
        int flag = 1;
        if(nums[start] == tmp[start]) {
            ++start;
            flag = 0;
        }
        if(nums[end] == tmp[end]) {
            --end;
            flag = 0;
        }
        if(flag == 1)
            break;
    }
    if(start==end)      //判断特殊情况例如  [1]
        return 0;
    return end - start +1;
}
