class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }

        TreeNode* tmp = root->right;
        root->right = mirrorTree(root->left);
        root->left = mirrorTree(tmp);
        return root;
    }
};