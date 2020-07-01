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


    // 避免产生多余的括号，当右子树为空的时候直接结束而不是加上（）

    void PartTree2str(string& s, TreeNode* t) {
        if (t == nullptr)
            return;

        // 使用to_string函数将数字转化为字符串
        string tmp = to_string(t->val);
        s += tmp;

        // 左子树为空的情况
        if (t->left == NULL) {
            // 如果右子树也为空，那么就是空树，结束
            if (t->right == NULL)
                return;
            // 右子树不为空，加上左子树的空代表的（）
            else
                s += "()";
        }
        // 左子树不为空
        else {
            s += '(';
            // 递归去判断左子树
            PartTree2str(s, t->left);
            s += ')';
        }

        // 如果右子树为空直接返回结束
        if (t->right == NULL) {
            return;
        }
        // 不为空再去递归判断右子树
        else {
            s += '(';
            PartTree2str(s, t->right);
            s += ')';
        }
    }
    string tree2str(TreeNode* t) {
        string s;
        PartTree2str(s, t);
        return s;
    }
};