class Solution {
public:
    ListNode* reverse(ListNode* first, ListNode* second){
        auto prev = second;
        while(first != second){
            auto temp = first->next;
            first->next = prev;
            prev = first;
            first = temp;
        }

        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       auto node = head;
       for(int i = 0; i<k; i++){
          if(!node){
            return head;
          }
          node = node->next;
       } 

       auto new_head = reverse(head, node);
       head->next = reverseKGroup(node, k);

       return new_head;
    }
};