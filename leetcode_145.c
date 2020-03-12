//  �������ĺ������ 


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

void _postorderTraversal(struct TreeNode* root,int* Arr,int* pi) {
    if(root == NULL)
        return;
    _postorderTraversal(root->left,Arr,pi);
    _postorderTraversal(root->right,Arr,pi);
    Arr[(*pi)++] = root->val;
}
////  ������ÿһ������ֵ�Ž����飬Ȼ��i++�����ǲ��ܲ������ܴ�i��������ͬһ��i����i�ĵ�ַ
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    *returnSize = size;
    int* Arr = (int *)malloc(sizeof(int)*size);
    int i = 0;
    _postorderTraversal(root,Arr,&i);
    return Arr;
}


