/*
** 相交链表
*/ 




typedef struct ListNode Node; 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    Node* curA = headA;
    Node* curB = headB;
    Node *longerlist = headA;
	Node *shortlist = headB;
    int gap;
    int lengthA = 0;
    int lengthB = 0;
    while(curA){
        ++lengthA;
        curA = curA->next;
    }
    while(curB){
        ++lengthB;
        curB = curB->next;
    }
    gap = abs(lengthA - lengthB);//求多余部分长度
	if (lengthA < lengthB)
	{
		longerlist = headB;
		shortlist = headA;
	}
	while(gap--) {
        longerlist = longerlist->next;
    }
    while(longerlist) {
        if(longerlist == shortlist)
            return longerlist;
        longerlist = longerlist->next;
        shortlist = shortlist->next;
        
    }
    return NULL ;
}
