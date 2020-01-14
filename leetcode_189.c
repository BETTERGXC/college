//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。 


//旋转一个数组中的元素 分三步
//第一步： 将整个数组逆置
//第二步： 将 k 之前的元素逆置
//第三步： 将 k 之后的元素逆置（包括k） 
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
