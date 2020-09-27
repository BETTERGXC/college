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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>res;
        if(root)
            q.push(root);
        while(!q.empty()){
            TreeNode* N = q.front();
            q.pop();
            res.push_back(N->val);
            if(N->left)
                q.push(N->left);
            if(N->right)
                q.push(N->right);
        }
        return res;
    }
};