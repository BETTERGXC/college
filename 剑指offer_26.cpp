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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL) {
            return false;
        }
        return hasSubStructure(A,B) || isSubStructure(A->left,B) 
        || isSubStructure(A->right,B);
    }

    bool hasSubStructure(TreeNode* A, TreeNode* B) {
        // if(!B)要在if(!A)前面，不然会出现A为空直接弹出false的情况
        if(B == NULL) {
            return true;
        }
        if(A == NULL) {
            return false;
        }
        if(A->val != B->val) {
            return false;
        }
        return hasSubStructure(A->left, B->left) 
        && hasSubStructure(A->right, B->right);
    }
};
