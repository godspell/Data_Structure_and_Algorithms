class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> pq;
        pq.push(root);
        while(!pq.empty()){
            int n = pq.size();
            for(int i = 0; i<n; i++){
                Node* t = pq.front();
                pq.pop();
                if(t->left){
                    pq.push(t->left);
                }
                if(t->right){
                    pq.push(t->right);
                }
                
                if(i==n-1){
                    t->next = NULL;
                }
                else{
                    t->next = pq.front();
                }
            }
        }
        
        return root;
    }
};