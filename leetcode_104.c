//  ��������������

int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int left = maxDepth(root->left)+1;
    int right = maxDepth(root->right)+1;
    return left>right?left:right;
}

/*  һ��ʼ��ʱ������
int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    return maxDepth(root->left)+1>maxDepth(root->right)+1?maxDepth(root->left)+1:maxDepth(root->right)+1;
}

��Ϊ���ִ�����Ĵεݹ飬���Գ�ʱ��������������left��right�������������εݹ�
*/ 
