//  ��ֵ������ 

//  ������Ȼ���Զ���ȫ�ֱ�����leetcode�ϵĺö��ⶨ����ȫ�ֱ����ͻᱨ��
//  ��Ȼ���Զ���ȫ�ֱ�����ֻ��Ҫ��������ֵ��ȫ�ֱ�����Ȼ������������ԱȺ͸��ڵ��ֵ���� 

int ret;
bool isEqual(struct TreeNode* root) {
    if(root == NULL)
        return true;
    if(root->val != ret)
        return false;
    return isEqual(root->left)&&isEqual(root->right);
    
}
bool isUnivalTree(struct TreeNode* root){
    ret = root->val;
    return isEqual(root);
}
