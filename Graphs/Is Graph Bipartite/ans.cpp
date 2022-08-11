class Solution {
public:
    bool bipartite;
    vector<bool> visited; 
    vector<int> col;
    
    void dfs(int i, int curr, vector<vector<int>> &edges){
        if(col[i] != -1 && col[i] != curr){
            bipartite = false;
            return;
        }
        
        col[i] = curr;
        if(visited[i]){
            return;
        }
        visited[i] = true;
        
        for(auto it : edges[i]){
            dfs(it, curr xor 1, edges);
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
         visited = vector<bool>(n, 0);
         col = vector<int>(n, -1);
        
         bipartite = true;
         for(int i = 0; i<n; i++){
             if(!visited[i]){
                 dfs(i, 0, graph);
             }
         }
        
        return bipartite;
    }
};
