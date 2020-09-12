class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(headA == NULL || headB == NULL) return NULL;
		ListNode* p = headA;
		ListNode* q = headB;
		while(p != q){
			if(p == NULL){
				p = headB;
			}
			else{
				p = p->next;
			}
			if(q == NULL){
				q = headA;
			}
			else{
				q = q->next;
			}
		}
		return p;
    }

};
