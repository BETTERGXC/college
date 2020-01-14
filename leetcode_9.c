//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

//我自己的做法是，先将给的数每一位数放在一个数组里边，然后从数组两边进行比较 
bool isPalindrome(int x){
    if(x<0)
        return false; 
    int count = 1;
    int tmp = x;
    while(x>0) {
        if((x/10)>0)
        count++;
        x = x/10;
    }
    int *arr = (int*)malloc(count*sizeof(int));
    for(int i = count-1;i>=0;i--) {
        arr[i] = tmp%10;
        tmp = tmp/10;
    }
    int left = 0;
    int right = count - 1;
    int ret = 1;
    while(left<right) {
        if(arr[left] != arr[right]) {
            ret = 0;
            break;
        }
        left++;
        right--;
    } 
    free(arr);
    if(ret == 1)
        return true;
    else
        return false;
}
