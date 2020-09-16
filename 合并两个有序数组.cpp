class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(m == 0 && n!= 0) {
            for(int i = 0; i < n; ++i) {
                A[i] = B[i];
            }
            return;
        }
        vector<int> tmp;
        int pos1 = 0;
        int pos2 = 0;
        while(pos1 < m && pos2 < n) {
            if(A[pos1] < B[pos2])
                tmp.push_back(A[pos1++]);
            else
                tmp.push_back(B[pos2++]);
        }
        while(pos1 < m) {
            tmp.push_back(A[pos1++]);
        }
        while(pos2 < n) {
            tmp.push_back(B[pos2++]);
        }
        
        for(int i = 0; i < m+n; i++) {
            A[i] = tmp[i];
        }
    }
};