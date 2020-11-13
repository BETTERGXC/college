class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int,int> m;
        for(int i = 0; i < data.size(); i++) {
            m[data[i]]++;
        }
        int flag = 0;
        for(int i = 0; i < data.size(); i++) {
            if(m[data[i]] == 1 && flag == 0) {
                flag = 1;
                *num1 = data[i];
            }
            if(m[data[i]] == 1 && flag == 1) {
                *num2 = data[i];
            }
        }
    }
};