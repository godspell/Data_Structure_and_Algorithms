class Solution:
    
    #Function to return list containing vertices in Topological order.
    def dfs(self, i, adj, visited, ans):
        visited[i] = 1
        for x in adj[i]:
            if visited[x] == 0:
                self.dfs(x, adj, visited, ans)
        ans.append(i)
        
    def topoSort(self, V, adj):
        # Code here
        ans = []
        visited = [0]*V
        
        for i in range(V):
            if visited[i] == 0:
                self.dfs(i, adj, visited, ans)
        
        ans.reverse()
        return ans