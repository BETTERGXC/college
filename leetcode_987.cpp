class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2,0));
        //dp[i][0] 表示当 arr[i-1] > arr[i] 前 i个数里边最长川流子数组长度
        //dp[i][1] 表示当 arr[i-1] < arr[i] 前 i个数里边最长川流子数组长度
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i-1] > arr[i]) {
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = 1;
            }
            else if(arr[i-1] < arr[i]) {
                dp[i][0] = 1;
                dp[i][1] = dp[i-1][0] + 1;
            }
            // 如果 arr[i] == arr[i-1] ，那就重新开始，都等于1
            else {
                dp[i][0] = 1;
                dp[i][1] = 1;
            }
        }
        int maxSize = 0;
        for(int i = 0; i < arr.size(); i++) {
            maxSize = max(maxSize, dp[i][0]);
            maxSize = max(maxSize, dp[i][1]);
        }
        return maxSize;
    }
};