  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<bool> visited(n, 0);
        vector<int> ans;
        queue<int> pq;
        pq.push(0);
        while(!pq.empty()){
            int t = pq.front();
            pq.pop();
            ans.push_back(t);
            for(auto it : adj[t]){
                if(!visited[it]){
                    pq.push(it);
                    visited[it] = true;
                }
            }
        }
        return ans;
    }
};