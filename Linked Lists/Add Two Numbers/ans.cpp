class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        int carry = 0;
        while(l1 || l2 || carry){
             int sum = 0;
             if(l1){
                sum += l1->val;
                l1 = l1->next;
             }

             if(l2){
                sum += l2->val;
                l2 = l2->next;
             }

             sum += carry;
             curr->next = new ListNode(sum%10);
             carry = sum/10;
             curr = curr->next;
        }

        return head->next;
    }
};