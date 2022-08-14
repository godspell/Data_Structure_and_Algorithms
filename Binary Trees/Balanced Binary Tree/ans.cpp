class Solution {
public:
    int find_height(TreeNode* root){
        if(!root) return 0;
        
        int lh = find_height(root->left);
        if(lh == -1) return -1;
        
        int rh = find_height(root->right);
        if(rh == -1) return -1;
        
        if(abs(lh - rh) > 1) return -1;
        
        return max(lh, rh) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
       return find_height(root) != -1; 
    }
};