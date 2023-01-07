class Solution {
public:
    Node* make(Node* root1, Node* root2){
        if(!root1) return root2;
        if(!root2) return root1;
        
        if(root1->data <= root2->data){
            root1->bottom = make(root1->bottom, root2);
            return root1;
        }
        else{
            root2->bottom = make(root1, root2->bottom);
            return root2;
        }
    }
    
    Node *flatten(Node *root)
    {
        // Your code here
        if(!root || !root->next) return root;
        Node* head = root, *nextHead = root->next;
        while(nextHead != NULL){
            Node* temp = nextHead->next;
            head->next = NULL;
            nextHead->next = NULL;
            head = make(head, nextHead);
            nextHead = temp;
        }
        return head;
    }
};