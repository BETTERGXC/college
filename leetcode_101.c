/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool ismarror(struct TreeNode* left,struct TreeNode* right) {
    if(left == NULL&&right == NULL)
        return true;
    if(left == NULL||right == NULL)
        return false;
    if(left->val == right->val)
        return ismarror(left->left,right->right)&&ismarror(left->right,right->left);
    return false;
}

bool isSymmetric(struct TreeNode* root){
    return ismarror(root,root);
}
