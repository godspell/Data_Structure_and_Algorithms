class Solution {
public:
  
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* lt = dummy, *prev_lt = NULL;
        for(int i = 0; i<left; i++){
           prev_lt = lt;
           lt = lt->next;
        }

        ListNode* rt = lt, *prev_rt = prev_lt;
        for(int i = left; i<=right; i++){
            ListNode* temp = rt->next;
            rt->next = prev_rt;
            prev_rt = rt;
            rt = temp;
        }
        prev_lt->next = prev_rt;
        lt->next = rt;

        return dummy->next;
    }
};