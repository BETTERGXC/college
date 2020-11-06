class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int max = nums[0];
        int min = nums[0];
        for(auto e : nums) {
            m[e]++;
            if(e == 0)
                continue;

            if(m[e] > 1) {
                return false;
            }
         
            if(e > max) {
                max = e;
            }
            if(min == 0 || e < min) {
                min = e;
            }
        }


        return (max - min) < 5 || ((m[0] > 1 )&& (max - min <= 5));
    }

private:
    map<int,int> m;
};