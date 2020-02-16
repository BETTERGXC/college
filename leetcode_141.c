// 环形链表 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;
bool hasCycle(struct ListNode *head) {
    Node* fast = head;
    Node* slow = head;
    if(head == NULL){
        return false;
    }
    if(head->next == NULL  ) {
        return false;
    }
    while(fast != NULL && fast->next != NULL) {  //快慢指针注意判断 fast 当前和下一个都不为空
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
}
