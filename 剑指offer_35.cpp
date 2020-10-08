// 首先复制结点，放在原来的结点后边
// 复制随机指针
// 将两个链表分开
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }

        Node* node = head;
        while(node) {
            Node* new_node = new Node(node->val);
            Node* tmp_next = node->next;
            node->next = new_node;
            new_node->next = tmp_next;
            new_node->random = nullptr;
            node = tmp_next;
        }
        node = head;
        while(node) {
            Node* tmp = node->next;
            if(node->random) {
                tmp->random = node->random->next;
            }
            node = node->next->next;
        }
        node = head;
        Node* ret_node = head->next;
        while(node->next) {
            Node*temp = node->next;
            node->next = temp->next;
            node = temp;
        }
        return ret_node;
    }
};