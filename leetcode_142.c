//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣?��������޻����򷵻�?null��

//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л�

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


