// 两数之和 


//给定一个整数数组 nums?和一个目标值 target，请你在该数组中找出和为目标值的那?两个?整数，并返回他们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 2);
    for(int i = 0;i<numsSize - 1;++i) {
        for(int j = i+1;j<numsSize;++j) {
            if(nums[i]+nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
    }
    return 0;
}
