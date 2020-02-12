/*
** 只出现一次的数字
*/ 




/*
** 先排序，再比较只出现一次的数
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
** 相同的数字异或结果为 0 ，0 异或任何数，等于这个数本身
*/ 
int singleNumber(int* nums, int numsSize) {
    int ret = 0;
    for(int i = 0;i<numsSize;i++){
        ret ^= nums[i];
    }
    return ret;
} 
