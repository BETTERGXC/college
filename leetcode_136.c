/*
** ֻ����һ�ε�����
*/ 




/*
** �������ٱȽ�ֻ����һ�ε���
*/ 
 int compare (const void * a, const void * b)
 {
   return ( *(int*)a - *(int*)b );
 }

 int singleNumber(int* nums, int numsSize){
     qsort (nums, numsSize, sizeof(int), compare);
     int res = 0;
     for(int i = 0;i<numsSize;i+=2) {
         if(i == numsSize - 1||nums[i] != nums[i + 1]) {
             res = nums[i];
             break;
        }
     }
     return res;
 }



/*
** ��ͬ�����������Ϊ 0 ��0 ����κ������������������
*/ 
int singleNumber(int* nums, int numsSize) {
    int ret = 0;
    for(int i = 0;i<numsSize;i++){
        ret ^= nums[i];
    }
    return ret;
} 
