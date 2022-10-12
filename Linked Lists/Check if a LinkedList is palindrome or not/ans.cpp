class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head, *prev = NULL;
        while(fast && fast->next){
            ListNode* temp = slow;
            fast = fast->next->next;
            slow = slow->next;
            temp->next = prev;
            prev = temp;
        }
        
        fast = fast ? slow->next : slow;
        slow = prev;
        
        while(fast && slow){
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        
        return true;
    }
};