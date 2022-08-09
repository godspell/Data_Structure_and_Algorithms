class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        while(curr){
            Node* nextnode = curr->next;
            Node* newnode = new Node(curr->val);
            curr->next = newnode;
            newnode->next = nextnode;
            curr = nextnode;
        } 
        curr = head;
        while(curr){
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        Node* dummy = new Node(0);
        Node* prev = dummy; 
        curr = head;
        while(curr){
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev = prev->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};