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
    // 前序遍历的第一个元素所在位置是根节点，中序遍历根节点两边是左右子树的元素
    TreeNode* _buildTree(vector<int>& preorder,vector<int>& inorder,int& index,int begin,int end) {
        TreeNode* proot = nullptr;
        // 如果index小于前序遍历数组的大小，说明还有元素
        if(index < preorder.size()) {
            proot = new TreeNode(preorder[index]);
        }

        // 找到中序遍历数组里根节点的位置
        int mid = begin;
        while(mid < end) {
            if(inorder[mid] == preorder[index])
                break;
            mid++;
        }

        // 先构造左子树，因为前序遍历里，遍历完根就会遍历左子树
        if(mid > begin) {
            proot->left = _buildTree(preorder,inorder,++index,begin,mid);
        }
        if(mid + 1 < end) {
            proot->right = _buildTree(preorder,inorder,++index,mid+1,end);
        }
        return proot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
       return  _buildTree(preorder,inorder,index,0,preorder.size());

    }
};