/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool _isValidBST(TreeNode* root, long low, long high) {
        if(root == NULL) 
            return true;
        if(root->val <= low || root->val >= high)
            return false;
        return _isValidBST(root->left, low, root->val) 
            && _isValidBST(root->right, root->val, high);

    }
};