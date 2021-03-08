//��֪��������������������������������Ҫ���ؽ���������
//����ǰ������Ľ���Ҹ���Ȼ��ȥ������������Ľ����������������
//�ٵݹ��ȥ��ɶ������Ĺ��� 

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
