//   二叉树的前序遍历 



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//   题目让返回一个数组，但是数组应该开多大，对于一棵树来说 TreeSize就是数组的大小

//  获取树的size
int TreeSize(struct TreeNode* root) {    
    if(root == NULL)
        return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}


//  将树的每一个结点的值放进数组，然后i++，但是不能参数不能传i，否则不是同一个i，传i的地址
void _preorderTraversal(struct TreeNode* root,int *Arr,int *pi) {
    if(root == NULL)  
        return;
    Arr[(*pi)++] = root->val;
    _preorderTraversal(root->left,Arr,pi);
    _preorderTraversal(root->right,Arr,pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    *returnSize = size;
    int *Arr = malloc(sizeof(int)*size);
    int i = 0;
    _preorderTraversal(root,Arr,&i);
    return Arr;
}
