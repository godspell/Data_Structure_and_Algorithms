class Solution {
public:
    ListNode* detectCycle(ListNode* headA){
        ListNode* fast = headA, *slow = headA;
        bool flag = false;
        while(fast && fast->next){
             fast = fast->next->next;
             slow = slow->next;
             if(slow == fast){
                 flag = true;
                 break;
             }
        }
        fast = headA;
        if(flag){
           while(fast != slow){
              fast = fast->next;
              slow = slow->next;
           }
          return slow;
        }
       return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* tail = headA;
       while(tail->next != NULL){
           tail = tail->next;
       }
       tail->next = headB;
       ListNode* ans = detectCycle(headA);
       tail->next = NULL;
       return ans;
    }
};