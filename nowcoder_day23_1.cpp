// 微信红包

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(),gifts.end());
        int count = 0;
        for(int i = 0;i<n;++i) {
            if(gifts[i] == gifts[n/2])
                count++;
        }
        if(count > n/2) 
            return gifts[n/2];
        else 
            return 0;
    }
};