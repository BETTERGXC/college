//  ��ͬ���� 

/*
**           ����������ĸ���㶼Ϊ�գ����ǿ�����������
**           ���������һ��Ϊ�գ�һ�ŷǿգ�������������ͬ�����ؼ�
**           ����������ĸ��ڵ��ֵ��ͬ����ȥ�ж����������������Ƿ��Ƿ���ͬ���������������Ƿ���ͬ 
*/ 


bool isEqualTree(struct TreeNode* left,struct TreeNode* right) {
    if(left == NULL&&right == NULL)
        return true;
    if(left == NULL||right == NULL)
        return false;
    if(left->val == right->val)
        return isEqualTree(left->left,right->left)&&isEqualTree(left->right,right->right);
    return false;
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    return isEqualTree(p,q);
}
