//����һ������ nums?��һ��ֵ val������Ҫԭ���Ƴ�������ֵ����?val?��Ԫ�أ������Ƴ���������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
//
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�




int removeElement(int* nums, int numsSize, int val){
    if(numsSize <= 0 || nums == NULL)
        return 0;
    int slow = 0;
    for(int i = 0;i<numsSize;i++) {
        if(nums[i] == val){

        }
        else {
            nums[slow] = nums[i];
            slow++;
        }
    } 
    return slow;
}
