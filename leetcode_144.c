//   ��������ǰ����� 



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
//   ��Ŀ�÷���һ�����飬��������Ӧ�ÿ���󣬶���һ������˵ TreeSize��������Ĵ�С

//  ��ȡ����size
int TreeSize(struct TreeNode* root) {    
    if(root == NULL)
        return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}


//  ������ÿһ������ֵ�Ž����飬Ȼ��i++�����ǲ��ܲ������ܴ�i��������ͬһ��i����i�ĵ�ַ
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
