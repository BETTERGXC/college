//  二叉树的最大深度

int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int left = maxDepth(root->left)+1;
    int right = maxDepth(root->right)+1;
    return left>right?left:right;
}

/*  一开始超时的做法
int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    return maxDepth(root->left)+1>maxDepth(root->right)+1?maxDepth(root->left)+1:maxDepth(root->right)+1;
}

因为里边执行了四次递归，所以超时！单独设置如上left和right变量，减少两次递归
*/ 
