//����һ������ͷ��� head �ķǿյ���������������м��㡣

//����������м��㣬�򷵻صڶ����м��㡣 



struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* slow,*fast;
    slow = head;
    fast = head;
    if(fast == NULL) {
        return NULL;
    }
    while(fast != NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    
    }
    return slow;
    
}
