class Solution {
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int>& arr) {
        vector<int> help(arr.size(), 1);
        for(int i = 0; i < arr.size()-1; i++) {
            if(arr[i+1] > arr[i]) {
                help[i+1] = help[i] + 1;
            }
        }
        int result = 0;
        for(int i = arr.size() - 1; i > 0; i--) {
            if(arr[i-1] > arr[i]) {
                help[i-1] = max(help[i-1], help[i] + 1);
            }
        }
        for(int i = 0; i < arr.size(); i++) {
            result += help[i];
        }
        return result;
    }
};
