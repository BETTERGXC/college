//对于非0递增序列(a1 < a2 < a3 < ... < an)如何覆盖每一个种类呢？
//举一个小例子：在2 3 4 5的序列中任意找三个数求和，保证没有其他的三个数的和大于它，你肯定会选择3，4，5；那如果需要找一个整数比其中任意三个数的和都大，且为最//小的一个，应该怎么选？
//答案为：（（2 + 3 + 4 + 5）- 2）+ 1 即可保证序列中任取三个数不可能比它大，且为符合条件的最小值。
//覆盖(a1,a2,...an)的数为(sum(a1, a2, ..., an) - a1) + 1;// a1的值为最小值
//1. 题目中存在最差情况为，一边没有，这时候需要将此种颜色所有的手套带走才可以保证题意。
//2. 第二中情况就是上面的例子所体现的情况，在左右两边分别找出能够覆盖全部颜色的最小数量
//3. 判断左右两边那一边需要拿的数量最小就拿那一边，然后在另一边随便拿一个就能保证题意。

// 我开始的时候不能了解为什么(sum(a1, a2, ..., an) - a1) + 1;就能够保证覆盖(a1~an)，通过上面的例
// 子有了一点感觉

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int left_sum = 0, left_min = INT_MAX;
        int right_sum = 0, right_min = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            // 左边或者右边没有的时候需要全部拿走(最差结果)
            if(left[i] * right[i] == 0)
            {
                sum += left[i] + right[i];
            }
            // 找到左边和右边分别最少的颜色的数量并计算总和
            else{
                left_sum += left[i];
                right_sum += right[i];
                left_min = min(left[i], left_min);
                right_min = min(right[i], right_min);
            }
        }
        // 找到左边和右边中较小的值，在另一边直接拿一个就可以保证题意
        return sum +min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
    }
};