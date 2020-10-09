//前序遍历 + 递归回溯。我们用前序遍历来一次提取所有二叉树中从 root 到叶节点的路径，
//并把路径上节点的和与 sum 比较。如果我们遍历到一条路径的叶节点了，
//然后需要切换到下一条路径的叶节点（比如题目示例中，我们遍历完了 5-4-11-7，
//现在要从 7 切换到 右边的 2），我们需要先从 temp 中把 7 pop_back。
//这样才能保证切换了之后，temp里的值会是：5，4，11，2；而不是：5，4，11，7，2

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        if(root == NULL) {
            return res;
        }

        recursion(root, sum);
        return res;
    }

    void recursion(TreeNode* root, int sum) {
        if(root == NULL) {
            return;
        }
        tmp.push_back(root->val);
        sum -= root->val;
        if(sum == 0 && root->left == NULL && root->right == NULL) {
            res.push_back(tmp);
        }
        recursion(root->left, sum);
        recursion(root->right, sum);
        tmp.pop_back();
    }
};