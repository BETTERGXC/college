//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//
//要求返回这个链表的深拷贝。 




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //  先将原链表的每个结点拷贝一份到原链表每个结点后边
        Node* cur = head;
        while(cur) {
            Node* Next = cur->next;
            Node* copyNode = (Node*)malloc(sizeof(Node));
            copyNode->val = cur->val;
            copyNode->next = NULL;
            copyNode->random = NULL;

            cur->next = copyNode;
            copyNode->next = Next;

            cur = Next;
        }

        //  置 random ; copyNode 的 random 就是 cur->next 的 random

        cur = head;
        while(cur) {
            Node* copyNode = cur->next;
            if(cur->random)
                copyNode->random = cur->random->next;
            else
                copyNode->random = NULL;
            cur = cur->next->next;
        }

        // 将 copy 好的链表结点从原链表上拆下来并连接在一起

        Node* copyHead,*copyTail;
        copyHead = NULL;
        copyTail = NULL;
        cur = head;
        while(cur) {
            Node* copyNode = cur->next;
            Node* Next = cur->next->next;
            if(copyHead == NULL) {
                copyHead = copyTail = copyNode;
            }
            else{
                copyTail->next = copyNode;
                copyTail = copyTail->next;
            }
            cur->next = Next;
            cur = cur->next;
        }
        return copyHead;
    }
};
