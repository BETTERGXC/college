
// 将两个结点的路径依次入栈，然后当路径长度不一样时，长的出栈，当路径长度一样时对比栈顶元素是否相等
// 若栈顶元素相等，则是公共祖先，若不相等，两个都出栈
class Solution {
public:

    bool GetPath(TreeNode* root,TreeNode* Node,stack<TreeNode*>& s) {
        if(root == nullptr)
            return false;
        s.push(root);

        if(root == Node)
            return true;
        
        //bool path = false;
        if( GetPath(root->left,Node,s))
            return true;
        if(GetPath(root->right,Node,s))
            return true;
        
        s.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        
        stack<TreeNode*> pPath;
        stack<TreeNode*> qPath;

        GetPath(root,p,pPath);
        GetPath(root,q,qPath);

        int psize = pPath.size();
        int qsize = qPath.size();

        TreeNode* ret = nullptr;
        while(psize && qsize) {
            if(psize>qsize){
                pPath.pop();
                psize--;
            }
            else if(qsize>psize) {
                qPath.pop();
                qsize--;
            }

            else {
                if(qPath.top() == pPath.top()) {
                    ret = pPath.top();
                    break;
                }
                else
                {
                    pPath.pop();
                    qPath.pop();
                    psize--;
                    qsize--;
                }
            }
                

        }

        return ret;
    }
};