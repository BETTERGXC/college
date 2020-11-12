class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here
        if(v > a[n-1])
            return n + 1;
        int left = 0;
        int right = n - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(v > a[mid]) {
                left = mid;
            }
            else if(v < a[mid]) {
                right = mid;
            }
            else {
                return mid + 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(a[i] >= v) {
                return i + 1;
            }
        }
        return n + 1;
    }
};