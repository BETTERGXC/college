class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int _max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < array.size(); ++i) {
            if(sum < 0) {
                sum = array[i];
            }
            else {
                sum += array[i];
            }
            if(sum >= _max) {
                _max = sum;
            }
        }
        return _max;
    }
};