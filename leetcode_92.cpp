/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* successor = nullptr; 
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) { 
            // 记录第 n + 1 个节点
            successor = head->next;
            return head;
        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode* last = reverseN(head->next, n - 1);

        head->next->next = head;
        // 让反转之后的 head 节点和后面的节点连起来
        head->next = successor;
        return last;
    }    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr)
            return head;
        if(m == 1) {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next,m-1,n-1);
        return head;
    }
};