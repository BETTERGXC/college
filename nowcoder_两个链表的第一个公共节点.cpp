// 方法1：计算两个链表的长度，让长的先走，等长度一样，再同时遍历，
//判断节点是否相同

// 方法2：两个链表同时往后走，谁先到空，就等于另一条链表的链表头，再往后遍历
//判断节点是否相同
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        if(p1 == NULL || p2 ==NULL)
            return NULL;
        while(p1 != p2) {
            if(p1 == NULL)
                p1 = pHead2;
            else
                p1 = p1->next;
            if(p2 == NULL)
                p2 = pHead1;
            else
                p2 = p2->next;
        }
        return p1;
    }
};