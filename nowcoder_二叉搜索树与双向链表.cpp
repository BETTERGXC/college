class Solution {
public:
    // pPrev标记刚刚转化的节点，pRoot表示现在要转化的二叉树，pRoot前一个处理的节点是pPrev
    void _Convert(TreeNode* pRoot, TreeNode*& pPrev)
    {
        // 空树：不用转化，直接返回
        if(nullptr == pRoot)
            return;
        
        // 将pRoot的左子树转化为双向链表
        _Convert(pRoot->left, pPrev);
        
        // pRoot的left指向其前一个处理的节点，即pPrev
        // pRoot的right域没有办法在本次递归中处理，因为下一个节点不知道
        // 在本次中只能处理当前节点的left
        pRoot->left = pPrev;
        
        // 前一个节点的right指针域没有处理，right指针域指向后一个节点，即pRoot
        if(pPrev)
            pPrev->right = pRoot;
        
        pPrev = pRoot;
        
        // 将pRoot的右子树转化为双向链表
        _Convert(pRoot->right, pPrev);
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(nullptr == pRootOfTree)
            return nullptr;
        
        // 找双向链表的第一个节点，即树中最小的节点
        TreeNode* pHead = pRootOfTree;
        while(pHead->left)
            pHead = pHead->left;
        
        // 使用prev标记刚刚转化过的节点
        TreeNode* prev = nullptr;
        _Convert(pRootOfTree, prev);
        return pHead;
    }
};