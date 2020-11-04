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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
        return nullptr;

        if(p == nullptr && q != nullptr) {
            return q;
        }
        if(p != nullptr && q == nullptr) {
            return p;
        }

        s1.push(root);
        s2.push(root);

        while(s1.top() != p) {
            if(s1.top()->val > p->val) {
                s1.push(s1.top()->left);
            }
            else if(s1.top()->val < p->val) {
                s1.push(s1.top()->right);
            }
            else {
                break;
            }
        }        

        while(s2.top() != q) {
            if(s2.top()->val > q->val) {
                s2.push(s2.top()->left);
            }
            else if(s2.top()->val < q->val) {
                s2.push(s2.top()->right);
            }
            else {
                break;
            }
        }

        int sz1 = s1.size();
        int sz2 = s2.size();


        if(sz1 != sz2) {
            if(sz1 > sz2) {
                while(sz1 != sz2) {
                    s1.pop();
                    sz1--;
                }
            }
            else if(sz1 < sz2) {
                while(sz1 != sz2) {
                    s2.pop();
                    sz2--;
                }
            }
        }

        while(s1.top() != s2.top()) {
            s1.pop();
            s2.pop();
        }

        return s1.top();
    }

private:
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
};