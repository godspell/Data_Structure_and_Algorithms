class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        bool flag = false;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                flag = true;
                break;
            }
        } 
        fast = head;
        if(flag){
           while(fast != slow){
            fast = fast->next;
            slow = slow->next;
          }
          return slow;
        }
        return NULL;
    }
};