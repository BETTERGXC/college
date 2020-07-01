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


    // ���������������ţ���������Ϊ�յ�ʱ��ֱ�ӽ��������Ǽ��ϣ���

    void PartTree2str(string& s, TreeNode* t) {
        if (t == nullptr)
            return;

        // ʹ��to_string����������ת��Ϊ�ַ���
        string tmp = to_string(t->val);
        s += tmp;

        // ������Ϊ�յ����
        if (t->left == NULL) {
            // ���������ҲΪ�գ���ô���ǿ���������
            if (t->right == NULL)
                return;
            // ��������Ϊ�գ������������Ŀմ���ģ���
            else
                s += "()";
        }
        // ��������Ϊ��
        else {
            s += '(';
            // �ݹ�ȥ�ж�������
            PartTree2str(s, t->left);
            s += ')';
        }

        // ���������Ϊ��ֱ�ӷ��ؽ���
        if (t->right == NULL) {
            return;
        }
        // ��Ϊ����ȥ�ݹ��ж�������
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