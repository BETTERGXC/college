/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode* pre;
        ListNode* cur = head;
        ListNode* fast = head;
        while(n--) {
            fast = fast->next;
        }
        if(fast == NULL)
            return head->next;
        while(fast) {
            fast = fast->next;
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return head;
        
    }
};