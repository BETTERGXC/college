class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 一定先让快慢指针往后走再判断，否则每次都是真
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};