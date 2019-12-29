//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//
//Ҫ�󷵻�������������� 




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
        //  �Ƚ�ԭ�����ÿ����㿽��һ�ݵ�ԭ����ÿ�������
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

        //  �� random ; copyNode �� random ���� cur->next �� random

        cur = head;
        while(cur) {
            Node* copyNode = cur->next;
            if(cur->random)
                copyNode->random = cur->random->next;
            else
                copyNode->random = NULL;
            cur = cur->next->next;
        }

        // �� copy �õ��������ԭ�����ϲ�������������һ��

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
