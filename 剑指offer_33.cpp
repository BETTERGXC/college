class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        // 如果大小小于 2 直接返回
        if(postorder.size() < 2) {
            return true;
        }
        
        return verify(postorder, 0, postorder.size() - 1);
    }

    bool verify(vector<int> postorder, int left, int right) {
        if(left >= right)
            return true;
        //获取根的值
        int rootValue = postorder[right];
        
        int k = left;
        while(k < right && postorder[k] < rootValue) {
            k++;
        }
        for(int i = k; i < right; i++) {
            if(postorder[i] < rootValue) {
                return false;
            }
        }
        /*
        if(!verify(postorder, left, k - 1))
            return false;
        if(!verify(postorder, k, right - 1))
            return false;
        return true;
        */
        //判断左右子树
        return verify(postorder, left, k - 1) 
        && verify(postorder, k, right - 1);
    }
};