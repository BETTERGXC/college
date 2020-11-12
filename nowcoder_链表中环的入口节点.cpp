class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next ) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode* meet = slow;
                while(head) {
                    if(head == slow)
                        return head;
                    head = head->next;
                    slow = slow->next;
                }
            }
        }
        return nullptr;
    }
};