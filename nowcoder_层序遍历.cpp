/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int count = q.size();
            vector<int> tmp;
            while(count--) {
                tmp.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};