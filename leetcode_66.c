// 加一 
//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    // 将数组里边的数转换为整数的方法不可行，数组可能超出一个数的范围
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
