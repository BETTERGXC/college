// 数组中出现次数超过一半的数字

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {

        sort(numbers.begin(),numbers.end());
        int count = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == numbers[numbers.size() / 2])
                count++;
        }
        if (count > numbers.size() / 2)
            return numbers[numbers.size() / 2];
        return 0;
    
    }
};