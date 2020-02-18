
//反转一个单链表。

//示例:
//
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    if(head == NULL) {
        return NULL;
    }
    if(head->next == NULL) {
        return head;
    }
    while(cur) {
        struct ListNode* tmp;
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}
