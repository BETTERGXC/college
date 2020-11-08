 // 二叉搜索树的中序遍历是有序的
 // 直接中序遍历，将结点放入数组，最后返回倒数第K 个
class Solution {
public:
    vector<int> ret;
    void InOrder(TreeNode* root) {
        if(root == nullptr)
            return;
        InOrder(root->left);
        ret.push_back(root->val);
        InOrder(root->right);    
    }
    int kthLargest(TreeNode* root, int k) {
        InOrder(root);
        return ret[ret.size() - k];
    }
};