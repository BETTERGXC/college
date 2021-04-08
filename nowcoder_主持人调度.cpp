class Solution {
public:
    /**
     ���ȣ�Ҫ�Ի��������

��ʼʱ����ȵģ�����ʱ���С����
��ʼʱ�䲻��ȵģ���ʼʱ���С����
��Σ�����һ�����ȼ����У�Ĭ������ͬʱ����

ֻ�ṩ����ʱ�䣬�����ǰ�Ŀ�ʼʱ��С�ڶ��׵Ľ���ʱ�䣬˵��û����
�����ǰ�Ŀ�ʼʱ����ڶ��׵Ľ���ʱ�䣬˵�����Կ���һ�������׳���
��󷵻ض��г���
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
