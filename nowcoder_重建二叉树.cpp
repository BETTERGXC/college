//已知二叉树的先序遍历结果和中序遍历结果，要求重建二叉树。
//根据前序遍历的结果找根，然后去遍历中序遍历的结果，划分左右子树
//再递归的去完成二叉树的构建 

class Solution {
public:
    TreeNode* help(vector<int> pre, int preleft, int preright, 
                   vector<int>vin, int vinleft, int vinright) {
        if(preleft > preright)
            return nullptr;
        TreeNode* root = new TreeNode(pre[preleft]);
        for(int i = vinleft; i <= vinright; i++) {
            if(vin[i] == pre[preleft]) {
                root->left = help(pre, preleft+1, preleft+i-vinleft, vin, vinleft, i-1);
                root->right = help(pre, preleft+i-vinleft+1, preright, vin, i+1, vinright);
                break;
            }
            
        }
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int presize = pre.size();
        int vinsize = vin.size();
        if(presize == 0 || vinsize == 0)
            return nullptr;
        TreeNode* root = help(pre, 0, presize-1, vin, 0, vinsize-1);
        return root;
    }
};
