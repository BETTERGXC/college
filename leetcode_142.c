//给定一个链表，返回链表开始入环的第一个节点。?如果链表无环，则返回?null。

//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;
struct ListNode *detectCycle(struct ListNode *head) {
    node* fast = head;
    node* slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            node* meet = slow;
            while(1) {
                if(meet == head) {
                return head;
                }
                head = head->next;
                meet = meet->next;
            }
        }
    }
    
    return NULL;
}


