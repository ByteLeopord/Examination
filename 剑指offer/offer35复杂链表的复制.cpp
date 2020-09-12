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
        if(head == NULL) return NULL;
        Node* p = head;
        //复制每个结点，放在右侧
        while(p){
            Node* next = p->next;
            
            Node* node = new Node(p->val);
            
            node->next = next;
            p->next = node;

            p = next;
        }
        //复制random
        p = head;
        while(p && p->next){
            if(p->random != NULL)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        //分开为两条链
        p = head;
        Node* res = p->next;
        Node* q = res;
        while(p && q){
            Node* next = q->next;
            
            p->next = q->next;
            if(q->next)                 //到最后一个结点只需要断开p
                q->next = q->next->next;
            
            p = next;
            if(p)                       //到最后一个结点
                q = p->next;
        }
        return res;
    }
};
