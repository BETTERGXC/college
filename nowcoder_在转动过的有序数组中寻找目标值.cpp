class Solution {
public:
    /**
     * 
     * @param A int整型一维数组 
     * @param n int A数组长度
     * @param target int整型 
     * @return int整型
     */
    int search(int* A, int n, int target) {
        // write code here
        int left = 0;
        int right = n-1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(A[mid] == target)
                return mid;
            //左侧有序
            if(A[mid] >= A[left]) {
                if(A[mid] > target && A[left] <= target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            //右侧有序
            else {
                if(A[mid] < target && A[right] >= target) {
                    left = mid+1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};