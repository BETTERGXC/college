class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
         
        ListNode *newhead = new ListNode(0);
         
        newhead->next = head;
         
        ListNode *prev = newhead;
        ListNode *curr = head;
         
        int count = 0;
         
        while(curr != nullptr && curr->next != nullptr){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
                count++;
            }
            else{
                if(count > 0){
                    prev->next = curr->next;
                    count = 0;
                }else{
                    prev = curr;
                }
                curr = curr->next;
            }
        }
         
        if(count > 0){
            prev->next = curr->next;
        }
         
        return newhead->next;       
    }
};