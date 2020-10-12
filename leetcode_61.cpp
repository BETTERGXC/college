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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        int lenth = 0;
        ListNode* cur = head;
        ListNode* tail;
        while(cur) {
            lenth++;
            tail = cur;
            cur = cur->next;
        }
        tail->next = head;

        ListNode* new_tail = head;
        for(int i = 0; i < lenth - (k % lenth) - 1; i++) {
            new_tail = new_tail->next;
        }
        ListNode* new_head = new_tail->next;
        new_tail->next = NULL;
        return new_head;

    }
};