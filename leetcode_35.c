//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//����Լ������������ظ�Ԫ�ء�

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
