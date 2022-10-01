#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    int ans = 0;
    bool find_dir(Node* root, bool dir, int key){
        if(!root) return false;
        if(root->data == key) return true;
        
        if(dir){
            if(find_dir(root->left, dir, key)){
                return true;
            }
            if(find_dir(root->right, !dir, key)){
                ans++;
                return true;
            }
        }
        else{
            if(find_dir(root->right, dir, key)){
                return true;
            }
            if(find_dir(root->left, !dir, key)){
                ans++;
                return true;
            }
        }
        
        return false;
    }
    
    Node* find_lca(Node* root, int first, int second){
        if(!root || root->data == first || root->data == second){
            return root;
        }
        
        Node* left_lca = find_lca(root->left, first, second);
        Node* right_lca = find_lca(root->right, first, second);
        
        if(!left_lca) return right_lca;
        if(!right_lca) return left_lca;
        
        return root;
    }
    
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      ans = 0;
      Node* lca = find_lca(root, first, second);
      bool dir = true;
      if(lca->data == first){
          find_dir(lca->left, dir, second);
          find_dir(lca->right, !dir, second);
      }
      else if(lca->data == second){
          find_dir(lca->left, dir, first);
          find_dir(lca->right, !dir, first);
      }
      else{
          find_dir(lca->left, dir, second);
          find_dir(lca->right, !dir, second);
          find_dir(lca->left, dir, first);
          find_dir(lca->right, !dir, first);
          return ans +1;
      }
      return ans;
    }
};

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
