// 逆置单链表

ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
 
        ListNode *n1,*n2,*n3;
        n1=NULL;
        n2=head;
        n3=n2->next;
 
        while(n2)
        {
            n2->next=n1;
            n1=n2;
            n2=n3;
            if(n3)
            n3=n3->next;
        }
        return n1;
    }