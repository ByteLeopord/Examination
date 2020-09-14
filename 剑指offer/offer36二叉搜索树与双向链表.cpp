/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* pre = NULL;
    Node* head = NULL;
    void change(Node* root){
        if(root == NULL)
            return;
        change(root->left);
        if(head == NULL){
            head = root;
            pre = root;
        }
        else{
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        change(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        
        change(root);

        head->left = pre;
        pre->right = head;
        
        return head;
    }
};
