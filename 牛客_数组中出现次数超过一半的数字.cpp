// 思想:如果一个数字在数组中出现的次数超过数组长度一半，那么数组中间位置的元素必然是这个数字

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        sort(numbers.begin(),numbers.end());
        int mid = numbers[numbers.size() / 2];
        int count = 0;
        for(int i = 0;i < numbers.size();++i) {
            if(mid == numbers[i])
                count++;
        }
        if(count > numbers.size() / 2)
            return mid;
        return 0;
    }
};