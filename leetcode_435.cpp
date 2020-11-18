//预先按照end排了序，所以选择 x 是很容易的。关键在于，如何去除与 x 相交的区间，选择下一轮循环的 x 呢？
//由于我们事先排了序，不难发现所有与 x 相交的区间必然会与 x 的end相交；
//如果一个区间不想与 x 的end相交，它的start必须要大于（或等于）x 的end

class Solution {
public:
    static bool cmp(vector<int>&arr1, vector<int>&arr2) {
        return arr1[1] < arr2[1];
    }
    int IntervalsSchedule(vector<vector<int>>intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int x_end = intervals[0][1];
        for(vector<int>& e : intervals) {
            int start = e[0];
            if(start >= x_end) {
                count++;
                x_end = e[1];
            }

        }
        return count;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        return intervals.size() - IntervalsSchedule(intervals);
    }
};