/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        stack<ListNode*> stk;
        ListNode* p = head;
        while(p) {
            stk.push(p);
            p = p->next;
        }
        p = head;
        while(p) {
            if(p->val != stk.top()->val)
                return false;
            else {
                p = p->next;
                stk.pop();
            }
        }
        return true;
    }
};