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
    /*
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;

    }
    */

    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL)
            return 0;
        q.push(root);
        int ret = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* N = q.front();
                if(N->left) {
                    q.push(N->left);
                }
                if(N->right) {
                    q.push(N->right);
                }
                q.pop();
            }
            ret++;
        }
        return ret;
    }
};