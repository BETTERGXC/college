//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。

int searchInsert(int* nums, int numsSize, int target){
    int ret = -1;
    for(int i = 0;i<numsSize;i++) {
        if(target == nums[i]){
            ret = i;
        }
    }
    if(ret >= 0)
        return ret;
    for(int i = 0;i<numsSize;i++) {
        if(nums[i] > target) {
            ret = i;
            break;
        }
        ret = numsSize;
    }
    return ret;
}
