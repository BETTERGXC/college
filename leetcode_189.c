//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ����� 


//��תһ�������е�Ԫ�� ������
//��һ���� ��������������
//�ڶ����� �� k ֮ǰ��Ԫ������
//�������� �� k ֮���Ԫ�����ã�����k�� 
void rotate(int* nums, int numsSize, int k){
    if(numsSize == 1) {

    }
    else{
        if(k>numsSize) {
            k = k%numsSize;
        }
        int left = 0;
        int right = numsSize -1;
        while(left<=right) {
            int tmp;
            tmp = nums[right];
            nums[right] = nums[left];
            nums[left] = tmp;
            ++left;
            --right;
        }
        left = 0;
        right = k;
        while(left<k - 1) {
            int tmp;
            tmp = nums[k - 1];
            nums[k - 1] = nums[left];
            nums[left] = tmp;
            ++left;
            --k;
        }
        int size = numsSize - 1;
        while(right<size) {
            int tmp;
            tmp = nums[size];
            nums[size] = nums[right];
            nums[right] = tmp;
            ++right;
            --size;
        }
    }

    

}
