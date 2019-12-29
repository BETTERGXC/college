//对链表进行插入排序。

 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*
    首先，需要一个头结点，否则如果插入的结点的值小于第一个结点，就要反复更正头结点
    要判断如果要插入的结点比排序好的链表的最后一个结点都大的情况
    注意置空，否则会出现奇奇怪怪的错误
*/
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;

    Node* sortHead = (Node*)malloc(sizeof(Node));
    sortHead->next = head;
    head = head->next;
    sortHead->next->next = NULL;

    while(head) {
        Node* prev = sortHead;
        Node* cur = sortHead->next;
        Node* headNext = head->next;
        while(cur) {
            if(cur->val > head->val) {
                prev->next = head;
                head->next = cur;
                break;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        if(cur == NULL) {       // 判断如果要插入的结点比排序好的链表的最后一个结点都大的情况
            prev->next = head;
            head->next = NULL;  // 置空
        }
        head = headNext;
    }
    return sortHead->next;
}
