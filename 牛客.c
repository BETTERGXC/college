
//����һ����������������е�����k����㡣 


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL || k<=0){
            return NULL;
        }
        struct ListNode* p;
        p = pListHead;
        int count = 1;
        while(p->next != NULL){
            count++;
            p = p->next;
             
        }
        if(k>count) {
            return NULL;
        }
        count = count-k;
        p = pListHead;
        while(count>0) {
            p = p->next;
            count--;
        }
        return p;
    }
