/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int xpre;
    int xdeep;
    int ypre;
    int ydeep;
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr)
            return false;
        dfs(root, 1, x, y, root->val);
        return (xpre != ypre) && (xdeep == ydeep);
    }

    void dfs(TreeNode* root, int deep, int x, int y, int pre) {
        if(root == nullptr) {
            return;
        }
        if(root->val == x) {
            xpre = pre;
            xdeep = deep;
        }
        else if(root->val == y) {
            ypre = pre;
            ydeep = deep;
        }
        else {
            dfs(root->left, deep+1, x, y, root->val);
            dfs(root->right, deep+1, x, y, root->val);
        }
    }
};
