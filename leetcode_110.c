/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int TreeHigh(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int L = TreeHigh(root->left);
    int R = TreeHigh(root->right);
    if(L == -1||R == -1)
        return -1;
    if(abs(L-R)>1)
        return -1;
    return TreeHigh(root->left)+1>TreeHigh(root->right)+1?TreeHigh(root->left)+1:TreeHigh(root->right)+1;
}
bool isBalanced(struct TreeNode* root){
    return TreeHigh(root) != -1;
}
