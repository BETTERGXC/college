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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return _isSymmetric(root->left, root->right);
    }

    bool _isSymmetric(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) {
            return true;
        }
        if(left == NULL || right == NULL) {
            return false;
        }
        return (left->val == right->val)
        && _isSymmetric(left->left, right->right)
        && _isSymmetric(left->right, right->left);
    }
};