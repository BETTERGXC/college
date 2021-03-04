class Solution {
public:
    int maxValue;
    int maxLen = INT_MIN;
    void backtrack(TreeNode* root, int len) {
        if(root->left == NULL && root->right == NULL) {
            if(len > maxLen) {
                maxLen = len;
                maxValue = root->val;
            }
            return;
        }
        if(root->left) {
            backtrack(root->left, len+1);
        }
        if(root->right) {
            backtrack(root->right, len+1);
        }
        return ;
    }
    int findBottomLeftValue(TreeNode* root) {
        backtrack(root, 0);
        return maxValue;
    }
};