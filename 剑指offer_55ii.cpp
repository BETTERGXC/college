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
    int getDeep(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int left = getDeep(root->left);
        if(left == -1)
            return -1;
        int right = getDeep(root->right);
        if(right == -1)
            return -1;
        
        if(left > right)
            return (left - right < 2) ? (left + 1) : -1;
        
        else if(left < right)
            return (right - left < 2) ? (right + 1) : -1;
        else 
            return right + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        cout << getDeep(root) << endl;
        return getDeep(root) != -1;
    }
};