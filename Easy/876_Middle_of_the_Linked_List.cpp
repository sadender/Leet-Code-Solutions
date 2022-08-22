class Solution {
public:
    ListNode* middleNode(ListNode* &head) {
        ListNode* l1 = head , *l2 = head;
        while(l2 != NULL && l2->next != NULL){
            l1 = l1->next;
            l2 = l2->next->next;
        }
        return l1;
    }
};