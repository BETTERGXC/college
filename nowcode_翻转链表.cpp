/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 关键问题在于 如何保存下一个结点，所以采用三指针
// 即保存前一个，也保存下一个
// 链表是不带头的链表
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        typedef struct ListNode node;
        node* Prev = NULL;
        node* Cur = pHead;
        node* Next = NULL;
        
        while(Cur) {
            Next = Cur->next;
            Cur->next = Prev;
            Prev = Cur;
            Cur = Next;
        }
        
        return Prev;
    }
};