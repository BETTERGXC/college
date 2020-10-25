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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) 
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode* ret = new ListNode(INT_MIN);
        ListNode* p = ret;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                if(p->val == INT_MIN) {
                    p->val = l1->val;
                    p->next = nullptr;
                }
                else {
                    ListNode* newNode = new ListNode(l1->val);
                    newNode->next = nullptr;
                    p->next = newNode;
                    p = p->next;
                }
                l1 = l1->next;
            }
            else {
                if(p->val == INT_MIN) {
                    p->val = l2->val;
                    p->next = nullptr;
                }
                else {
                    ListNode* newNode = new ListNode(l2->val);
                    newNode->next = nullptr;
                    p->next = newNode;
                    p = p->next;
                }
                l2 = l2->next;
            }
        }
        if(l1) {
            p->next = l1;
        }
        else {
            p->next = l2;
        }
        return ret;
    }
};