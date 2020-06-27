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
// 后序遍历的最后一个元素是根节点，中序遍历根节点两边是左右子树的元素
    TreeNode* _buildTree(vector<int>& inorder,vector<int>& postorder,int& index,int begin,int end) {
        TreeNode* proot = nullptr;
        // 如果没有元素了，返回空
        if(index < 0)
            return proot;

        // 还原根节点
        proot = new TreeNode(postorder[index]);
        
        // 找到根节点
        int mid = begin;
        while(mid < end) {
            if(inorder[mid] == postorder[index])
                break;

            mid++;
        }

        // 如果右子树不为空，构造右子树
        if(mid + 1 < end) {
            proot->right = _buildTree(inorder,postorder,--index,mid+1,end);
        }

        // 如果左子树不为空，构造左子树
        if(mid > begin) {
            proot->left = _buildTree(inorder,postorder,--index,begin,mid);
        }
        return proot;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        return _buildTree(inorder,postorder,index,0,postorder.size());
    }
};