class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ret;
    vector<int> tmp;
    void backtrack(TreeNode* root, int sum) {
        if(root == NULL) {
            return;
        }
        sum -= root->val;
        tmp.push_back(root->val);
        if(sum == 0 && root->left == NULL && root->right == NULL) {
            ret.push_back(tmp);
            return;
        }
        if(root->left) {
            backtrack(root->left, sum);
            tmp.pop_back();
        }
        if(root->right) {
            backtrack(root->right, sum);
            tmp.pop_back();
        }
        
        
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        // write code here
        backtrack(root, sum);
        return ret;
    }
};