from typing import List
class Solution:
    def dfs(self, i, adj, visited, parent):
        visited[i] = 1
        for x in adj[i]:
            if x != parent:
               if visited[x] == 1:
                  return True
               if visited[x] == 0 and self.dfs(x, adj, visited, i):
                  return True
            
        return False
            
    #Function to detect cycle in an undirected graph.
    def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        #Code here
        visited = [0]*V
        cycle = False
        
        for i in range(V):
            if visited[i] == 0 and self.dfs(i, adj, visited, -1):
                cycle = True
                break
        
        return cycle