class Solution {
  public:
    bool iscycle(vector<int> adj[], vector<bool> &visited, int i, int parent){
    queue<pair<int, int>> pq;
    visited[i] = true;
    pq.push({i, -1});
    while(!pq.empty())
    {
        pair<int, int> p = pq.front();
        int a = p.first;
        int b = p.second;
        pq.pop();
        for(auto it : adj[a])
        {
            if(it != b)
            {
                if(visited[it])
                return true;
                else
                {
                    visited[it] = true;
                    pq.push({it, a});
                }
            }
        }
    }
    return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
    
        vector<bool> visited(n, 0);
        for(int i=0; i<n; i++)
        {
            if(!visited[i] && iscycle(adj, visited, i, -1))
            return true;
        }
        return false;
    }
};