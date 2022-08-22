class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // When length is odd, middle is always palindromic, the middle pointer goes to exactly middle node, end pointer goes exactly to end node
        // When length is even, the middle pointer goes to a node right before middle, end pointer goes to a node right before end node
        ListNode* toEnd = head,* toMiddle = head;
        while (toEnd->next != NULL && toEnd->next->next != NULL) {
            toMiddle = toMiddle->next;
            toEnd = toEnd->next->next;
        }
                
        // Create new list of the opposite half reversed
        ListNode *temp_head = toMiddle->next;
        ListNode *next,* newList;
        newList = NULL;
        
        while (temp_head != NULL) {
            // Puts a pointer on next temporary head
            next = temp_head->next;
            // Connect the temporary head with the new list
            temp_head->next = newList;
            // The connected list becomes the new list
            newList = temp_head;
            // Move the temporary head to the next node in the original list
            temp_head = next;
        }
        temp_head = newList;
        
        while (temp_head != NULL && head != NULL) {
            if(temp_head->val != head->val) {
                return false;
            }
            temp_head = temp_head->next;
            head = head->next;
        }
        return true;
    }
    
};