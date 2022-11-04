void dfs(int idx, vector<int> adj[], vector<int> &v, vector<int>&visited){
        visited[idx] = true;
        v.push_back(idx);
        for(auto it : adj[idx]){
            if(!visited[it]){
                dfs(it, adj, v, visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> v, visited(V, 0);
        dfs(0, adj, v, visited);
        return v;
    }