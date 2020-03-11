//  平衡二叉树 



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


// 第二种 
int Depth(struct TreeNode* root){                        //   算深度 
    if(root == NULL)
        return 0;
    int leftDepth = Depth(root->left);
    int rightDepth = Depth(root->right);

    return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
}

bool isBalanced(struct TreeNode* root) {
    if(root == NULL)
        return true;
    int leftDepth = Depth(root->left);
    int rightDepth = Depth(root->right);

    return abs(leftDepth-rightDepth)<2                 //  如果两树的深度差小于二且左数平衡右数也平衡则为平衡二叉树 
            && isBalanced(root->left)
            && isBalanced(root->right);
}
