class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto e:nums) {
            pq.push(e);
        }

        while(--k) {
            pq.pop();
        }

        return pq.top();
    }
};