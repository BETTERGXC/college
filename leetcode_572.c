/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isEqual(struct TreeNode* l,struct TreeNode* r) {
    if(l == NULL&&r == NULL)
        return true;
    if(l == NULL||r == NULL)
        return false;
    if(l->val == r->val)
        return isEqual(l->left,r->left)&&isEqual(l->right,r->right);
    else
        return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(s == NULL&&t == NULL)
        return true;
    if(s == NULL||t == NULL)
        return false;
    if(s->val == t->val)
        return isEqual(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);  //  判断  s是 1，1   t是 1的情况 
    return isSubtree(s->left,t)||isSubtree(s->right,t);
}
