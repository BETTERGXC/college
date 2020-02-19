/* 
** 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。  
*/ 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL) 
        return l2;
    if(l2 == NULL)
        return l1;
    struct ListNode* tail = NULL;
    struct ListNode* head = NULL;
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    while(cur1 && cur2) {
        if(cur1->val < cur2->val) {
            if(head == NULL) {
                head = cur1;
                tail = cur1;
                cur1 = cur1->next;
            }
            else {
                tail->next = cur1;
                tail = tail->next;
                cur1 = cur1->next;
                
            }
        }
        else {
            if(head == NULL) {
                head = cur2;
                tail = cur2;
                cur2 = cur2->next;
            }
            else{
                tail->next = cur2;
                cur2 = cur2->next;
                tail = tail->next;
            }
        }
    }
    if(cur2 == NULL) {
        tail->next = cur1;
    }
    else{
        tail->next = cur2;
    }
    return head;
}
