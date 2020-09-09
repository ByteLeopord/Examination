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
    ListNode* reverse(ListNode* root){
        ListNode* p = root;
        ListNode* pre = NULL;
        while(p){
            ListNode* next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
    vector<int> reversePrint(ListNode* head) {
        if(head == NULL) return {};
        vector<int> res;
        ListNode* p = reverse(head);
        while(p){
            res.push_back(p->val);
            p = p->next;
        }
        return res;
    }
};
