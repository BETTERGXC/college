//  单值二叉树 

//  这道题居然可以定义全局变量，leetcode上的好多题定义了全局变量就会报错，
//  既然可以定义全局变量，只需要将根结点的值给全局变量，然后遍历二叉树对比和根节点的值即可 

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
