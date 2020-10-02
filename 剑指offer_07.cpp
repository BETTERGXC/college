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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    // 通过前序找到根节点，通过中序划分左右子树
    // begin 和 end 是中序的
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, 
    int root, int begin, int end) {
        if(begin > end) {
            return NULL;
        }

        TreeNode* ret_root = new TreeNode(preorder[root]);
        int i = begin;
        while(preorder[root] != inorder[i])
            i++;
        
        ret_root->left = build(preorder, inorder, root+1, begin, i-1);
        // 右子树根节点的索引是  根节点加上左子树长度加上1
        ret_root->right = build(preorder, inorder, root+1+i-begin, i+1, end);

        return ret_root;
    }   
};