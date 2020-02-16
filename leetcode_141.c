// �������� 


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
    while(fast != NULL && fast->next != NULL) {  //����ָ��ע���ж� fast ��ǰ����һ������Ϊ��
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
}
