//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* small_head=NULL;
        struct ListNode* big_head=NULL;
        struct ListNode* small = small_head;
        struct ListNode* big = big_head;
        struct ListNode* head = pHead;
        if(pHead == NULL) {
            return NULL;
        }
        if(head->next == NULL||head==NULL) {
            return head;
        }
         
        while(head) {
            if(head->val<x) {
                if(small_head == NULL) {
                    small_head = head;
                    small = small_head;
                    head = head->next;
                }
                else{
                    small->next = head;
                    head = head->next;
                    small = small->next;
                    small->next=NULL;
                }
            }
            else{
                if(big_head == NULL) {
                    big_head = head;
                    big = big_head;
                    head = head->next;
                }
                else{
                    big->next = head;
                    head = head->next;
                    big = big->next;
                    big->next=NULL;
                }
            }
        }
        if(small_head == NULL) {
            return big_head;
        }
        if(big_head == NULL){
            return small_head;
        }
        if(small_head != NULL && big_head != NULL) {
            small->next = big_head;
            return small_head;
        }
    }
};
