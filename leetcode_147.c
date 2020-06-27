//��������в�������

 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*
    ���ȣ���Ҫһ��ͷ��㣬�����������Ľ���ֵС�ڵ�һ����㣬��Ҫ��������ͷ���
    Ҫ�ж����Ҫ����Ľ�������õ���������һ����㶼������
    ע���ÿգ�������������ֵֹĴ���
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
        if(cur == NULL) {       // �ж����Ҫ����Ľ�������õ���������һ����㶼������
            prev->next = head;
            head->next = NULL;  // �ÿ�
        }
        head = headNext;
    }
    return sortHead->next;
}
