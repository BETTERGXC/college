//��ת������ 

/*
**һ��ʼ��������ֻ�ǻ�����������ֵ�������������������ύ����
**�����뵽����������õĶ������������˵Ĳ�������������ֵ��
**��������������������Ӧ��ָ���ָ��ȥ����������������Ľ���!
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
