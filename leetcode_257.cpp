class Solution {
public:
    vector<int> tmp;
    vector<string> result;
    void backTrack(TreeNode* root) {
        tmp.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            string partRet;
            for(int i = 0; i < tmp.size()-1; i++) {
                partRet += to_string(tmp[i]);
                partRet += "->";
            }
            partRet += to_string(tmp[tmp.size()-1]);
            result.push_back(partRet);
            return;
        }

        if(root->left) {
            backTrack(root->left);
            tmp.pop_back();
        }
        if(root->right) {
            backTrack(root->right);
            tmp.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) {
            return result;
        }
        backTrack(root);
        return result;
    }
};