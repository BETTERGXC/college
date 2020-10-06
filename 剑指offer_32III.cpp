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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if(root == NULL) {
            return v;
        }
        q.push(root);
        int flag = 1;
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for(int i = 0; i < size; i++) {
                tmp.push_back(q.front()->val);
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(flag % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            flag++;
            v.push_back(tmp);
        }
        return v;
    }
};