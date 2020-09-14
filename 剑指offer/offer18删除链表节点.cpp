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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* prehead = new ListNode(-1);
        prehead->next = head;
        ListNode* p = head;
        ListNode* pre = prehead;
        while(p){
            ListNode* next = p->next;
            if(p->val == val){
                pre->next = next;
                break;
            }
            pre = p;
            p = next;
        }
        return prehead->next;
    }
};
