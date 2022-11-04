class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node* n){
        if(!n) return NULL;
        if(mp.find(n) != mp.end()) return mp[n];
        Node* clone = new Node(n->val);
        mp[n] = clone;
        for(auto it : n->neighbors){
            clone->neighbors.push_back(dfs(it));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};