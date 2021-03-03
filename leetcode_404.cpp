//递归法
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftSum = sumOfLeftLeaves(root->left);
        int rightSum = sumOfLeftLeaves(root->right);
    
        int midValue = 0;
        //左叶子的定义 一个节点的左孩子存在，且左孩子没有左右孩子
        if(root->left && !root->left->left && !root->left->right) {
            midValue = root->left->val;
        }
        return midValue + leftSum + rightSum; 
    }
};


//迭代法
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        stack<TreeNode*> st;
        st.push(root);
        int result = 0;
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(node->left && !node->left->left && !node->left->right) {
                result += node->left->val;
            }
            if(node->left)
                st.push(node->left);
            if(node->right)
                st.push(node->right);
        }
        return result;
    }
};