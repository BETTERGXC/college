// ����������������� 






// �ȶ���һ����ʱ���飬������ nums �ڵ�Ԫ�ؽ�������Ȼ�����β���бȽϣ���� start�����++
// ��� end�����--��ֱ����βԪ�ض�����ͬ����Ӳ���ͬ��λ�ý���������

// �� qsort �����ֹ��ʱ
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
    if(start==end)      //�ж������������  [1]
        return 0;
    return end - start +1;
}
