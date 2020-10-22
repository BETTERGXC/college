/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 先遍历两个链表，然后让长的先走，等长度一样，在逐个遍历比较
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *pA = headA;
        int lenA = 0;
        ListNode *pB = headB;
        int lenB = 0;
        while(pA != nullptr) {
            lenA++;
            pA = pA->next;
        }
        while(pB != nullptr) {
            lenB++;
            pB = pB->next;
        }

        pA = headA;
        pB = headB;
        while(lenA != lenB) {
            if(lenA > lenB) {
                pA = pA->next;
                lenA--;
            }
            else if(lenA < lenB) {
                pB = pB->next;
                lenB--;
            }
        }

        while(pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }

        return pA;
    }
};