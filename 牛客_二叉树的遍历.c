#include<stdio.h>
#include<malloc.h>

typedef struct TreeNode {
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// �ݹ�Ĺ�����
TreeNode* Rebuild(char* a,int* pi) {
    // �����λ��Ϊ # �򷵻ؿ�
    if(a[*pi] == '#')
        return NULL;
    // ��Ϊ # �򹹽���
    else{
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->ch = a[*pi];
        ++(*pi);
        root->left = Rebuild(a,pi);
        ++(*pi);
        root->right = Rebuild(a,pi);
        return root;
    }
}

// �������
void Inorder(TreeNode* root) {
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%c ",root->ch);
    Inorder(root->right);
}

int main() {
    // ��Ŀ˵���Ȳ�����100�����Զ��� char a[100]
    char a[100];
    scanf("%s",a);
    
    int i = 0;
    TreeNode* root = Rebuild(a,&i);
    Inorder(root);
}

