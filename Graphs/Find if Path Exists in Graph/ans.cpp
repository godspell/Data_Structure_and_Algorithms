class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &visited){
        visited[i] = 1;
        for(auto it : adj[i]){
            if(!visited[it]){
               dfs(it, adj, visited);
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> visited(n, 0);
        
        dfs(source, adj, visited);
        if(visited[dest]) return true;
        
        return false;
    }
};