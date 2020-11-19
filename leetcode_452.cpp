class Solution {
public:
    static bool cmp(vector<int>&arr1, vector<int>&arr2) {
        return arr1[1] < arr2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end(),cmp);

        int count = 1;
        int x_end = points[0][1];
        for(vector<int> e : points) {
            int start = e[0];
            if(start > x_end) {
                count++;
                x_end = e[1];
            }
        }

        return count;
    }
};