/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool backtrack(TreeNode* root, int sum, int* flag) {
        if(!root->left && !root->right) {
            if(sum == root->val) {
                (*flag) = 1;
                return true;
            }
            else 
                return false;
        }
        if(*flag != 1 && root->left) {
            backtrack(root->left, sum - root->val, flag);
        }
        if(*flag != 1 && root->right) {
            backtrack(root->right, sum - root->val, flag);
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return false;
        if(root->val == sum && !root->left && !root->right) 
            return true;
        int flag = 0;
        backtrack(root, sum, &flag);
        if(flag == 1)
            return true;
        return false;
    }
};
