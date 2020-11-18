class Solution {
public
    void dfs(vectorint&num, int start, vectorvectorint&ret, vectorint&path,int& sum,int& target) {
        if(sum == target) {
            ret.push_back(path);
            return;
        }
        if(sum  target) 
            return;
        
        for(int i = start; i  num.size(); i++) {
            sum += num[i];
            path.push_back(num[i]);
            dfs(num,i+1,ret,path,sum,target);
            sum -= num[i];
            path.pop_back();
            while(num[i] == num[i+1] && i  num.size()) {
                i++;
            }
        }
    }
    vectorvectorint  combinationSum2(vectorint &num, int target) {
        vectorvectorint ret;
        vectorint path;
        if(num.empty())
            return ret;
        int sum = 0;
        sort(num.begin(),num.end());
        dfs(num,0,ret,path,sum,target);
        return ret;
    }
};