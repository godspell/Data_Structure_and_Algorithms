class Solution:
    
    #Function to return a list containing the DFS traversal of the graph.
        
    def dfsOfGraph(self, V, adj):
        # code here
        ans = []
        def dfs(i):
           ans.append(i)
           for x in adj[i]:
               if x not in ans:
                  dfs(x)
        
        dfs(0)
        return ans