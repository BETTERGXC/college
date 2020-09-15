
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        // write code here
        if(!root)
            return 0;
        return (max(maxDepth(root->left),maxDepth(root->right))) + 1;
    }
};