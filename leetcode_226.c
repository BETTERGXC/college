//反转二叉树 

/*
**一开始还在想这只是换左右子树的值，左右子树的子树不会交换，
**最后才想到，这棵树是用的二叉链表，交换了的不是左右子树的值，
**而是左右子树，所以相应的指针会指过去，完成子树的子树的交换!
*/
struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
        return NULL;
    struct TreeNode* right = invertTree(root->right);
    struct TreeNode* left = invertTree(root->left);
    root->left = right;
    root->right = left;
    return root;
}
