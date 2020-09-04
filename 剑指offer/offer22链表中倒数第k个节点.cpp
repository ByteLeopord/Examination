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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* node = head;
        int cnt = 1;
        while(node && cnt < k){
            cnt++;
            node = node->next;
        }
        if(cnt < k){
            return head;
        }
        ListNode* pk = head;
        while(node->next){
            pk = pk->next;
            node = node->next;
        }
        return pk;
    }
};
