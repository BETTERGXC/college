// Ѱ�������������� 


//����һ���������͵�����?nums�����дһ���ܹ��������顰�����������ķ�����
//
//���������������������������ģ����������������������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//
//������鲻����������������ô����Ӧ�÷��� -1����������ж��������������ô����Ӧ�÷��������ߵ���һ����
//


int pivotIndex(int* nums, int numsSize){
    int Sum = 0;
    for(int i = 0;i<numsSize;++i) {
        Sum += nums[i];
    } 
    int left_sum = 0;
    for(int i = 0;i<numsSize;++i) {
        if((Sum - nums[i] - left_sum) == left_sum)
            return i;
        left_sum += nums[i];
    }
    return -1;
}
