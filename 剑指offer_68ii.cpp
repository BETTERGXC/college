/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
    
        TreeNode* leftNode = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightNode = lowestCommonAncestor(root->right,p,q);

         if(leftNode == nullptr)
            return rightNode;
        if(rightNode==nullptr)
            return leftNode;

        return root;
    }
};