// 使用快慢指针，如果慢的追上快的，说明陷入了循环，就返回 false


class Solution {
public:

    int getNext(int n) {
        int ret = 0;
        while(n > 0) {
            int tmp = n % 10;
            n /= 10;
            ret += tmp * tmp;
        }
        return ret;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while(fast != 1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
            if(slow == fast) {
                return false;
            }
        }
        return true;
    }
};