//   ��������������� 



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
void _inorderTraversal(struct TreeNode* root,int *Arr,int *pi) {
    if(root == NULL)
        return;
    _inorderTraversal(root->left,Arr,pi);
    Arr[(*pi)++] = root->val;
    _inorderTraversal(root->right,Arr,pi);
}
//  ������ÿһ������ֵ�Ž����飬Ȼ��i++�����ǲ��ܲ������ܴ�i��������ͬһ��i����i�ĵ�ַ
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    *returnSize = size;
    int* Arr = (int *)malloc(sizeof(int)*size);
    int i = 0;
    _inorderTraversal(root,Arr,&i);
    return Arr;

}
