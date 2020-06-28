class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        // 如果是空树直接返回
        vector<vector<int>> ret;
        if(nullptr == root)
            return ret;
        
        queue<TreeNode*> q;
        q.push(root);   // 已经将第一层节点放到队列中
        
        while(!q.empty())
        {
            // 一次性将一层的所有节点全部遍历完
            vector<int> level;
            int levelSize = q.size();
            
        // 该for将本层节点变量完成后，已经将下一层节点保存到队列中
            for(size_t i = 0; i < levelSize; ++i)
            {
                TreeNode* pCur = q.front();
                level.push_back(pCur->val);
                
                // 如果该节点有左右子树，分别将左右子树入队列
                if(pCur->left)
                    q.push(pCur->left);
                
                if(pCur->right)
                    q.push(pCur->right);
                
                q.pop();
            }
            
            ret.push_back(level);
        }
        
        return ret;
    }
};