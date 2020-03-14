//  相同的树 

/*
**           如果两棵树的根结点都为空，则都是空树，返回真
**           如果两棵树一颗为空，一颗非空，则两棵树不相同，返回假
**           如果两棵树的根节点的值相同，则去判断两棵树的左子树是否是否相同两棵树的右子树是否相同 
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
