// ��һ 
//����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��
//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    // ��������ߵ���ת��Ϊ�����ķ��������У�������ܳ���һ�����ķ�Χ
    // int sum = 0;
    // for(int i = digitsSize - 1,j = 0;i>=0;--i,++j){
    //     sum += digits[i] * pow(10,j); 
    // }
    // ++sum;
    // int i = sum;
    // int lenth = 0;
    // while(i>0) {
    //     lenth++;
    //     i = i/10;
    // }
    // int *arr = (int*)malloc(lenth*sizeof(int));
    // for(int i = lenth - 1;i>=0;--i) {
    //     arr[i] = sum%10;
    //     sum = sum/10;
    // }
    // //*returnSize = (int *)malloc(sizeof(int));
    // *returnSize = lenth;
    // return arr;


    for (int i = digitsSize - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0) {
                *returnSize = digitsSize;
                return digits;
            }
        }
        int* arr = (int*)malloc((digitsSize+1)*sizeof(int));
        for(int i = 1;i<digitsSize+1;++i) {
            arr[i] = 0;
        }
        arr[0] = 1;
        *returnSize = (digitsSize+1);
        return arr;


}
