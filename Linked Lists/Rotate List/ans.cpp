class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;
        int len = 0;
        while(curr->next){
            len++;
            curr = curr->next;
        }
        len++;
        k = k%len;
        curr->next = head;
        while(--len >= k){
            curr = curr->next;
        }
        ListNode* new_head = curr->next;
        curr->next = NULL;
        return new_head;
    }
};