class Solution {
public:
    /**
     首先：要对活动进行排序：

开始时间相等的，结束时间从小到大
开始时间不相等的，开始时间从小到大
其次：建立一个优先级队列：默认升序，同时处理活动

只提供结束时间，如果当前的开始时间小于队首的结束时间，说明没空闲
如果当前的开始时间大于队首的结束时间，说明可以空闲一个，队首出队
最后返回队列长度
     */
    struct cmp {
        bool operator()(vector<int>&arr1, vector<int>&arr2) {
            if(arr1[0] == arr2[0]) {
                return arr1[1] < arr2[1];
            }
            return arr1[0] < arr2[0];
        }
    }mycmp;
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        // write code here
        if(n == 1 || n == 0)
            return n;
        sort(startEnd.begin(), startEnd.end(), mycmp);
        priority_queue<int,vector<int>, greater<int>> pq;
        pq.push(startEnd[0][1]);
        for(int i = 1; i < n; i++) {
            if(pq.top() <= startEnd[i][0]) {
                pq.pop();
            }
            pq.push(startEnd[i][1]);
        }
        return pq.size();
    }
};
