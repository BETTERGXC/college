#include<stdio.h>
#include<malloc.h>

typedef struct TreeNode {
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// 递归的构建树
TreeNode* Rebuild(char* a,int* pi) {
    // 如果该位置为 # 则返回空
    if(a[*pi] == '#')
        return NULL;
    // 不为 # 则构建树
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

// 中序遍历
void Inorder(TreeNode* root) {
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%c ",root->ch);
    Inorder(root->right);
}

int main() {
    // 题目说长度不超过100，所以定义 char a[100]
    char a[100];
    scanf("%s",a);
    
    int i = 0;
    TreeNode* root = Rebuild(a,&i);
    Inorder(root);
}

