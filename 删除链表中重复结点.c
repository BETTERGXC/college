/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL)
            return pHead; 
        ListNode* cur = pHead;
        ListNode* next = cur->next;
        ListNode* NewHead,*NewTail;
        NewHead = NewTail = (ListNode*)malloc(sizeof(ListNode));
        NewHead->next = NULL;
        while(next) {
            if(cur->val == next->val){
                while(next && next->val == cur->val) {
                    next = next->next;
                }
            }
            else {
                NewTail->next = cur;
                NewTail = cur;
                NewTail->next = NULL;  //注意置空
            }
            cur = next;
            if(cur)                    //
                next = cur->next;
        }
        if(cur) {                      //若最后一个结点的值只有一个，而next已经为空
            NewTail->next = cur;
        }
        return NewHead->next;
    }
};
