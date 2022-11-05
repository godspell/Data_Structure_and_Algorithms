from collections import deque
class Solution:
    
    #Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, V, adj):
        # code here
        ans = []
        visited = [False]*V
        pq = deque()
        pq.append(0)
        visited[0] = True
        
        while pq:
            t = pq.popleft()
            ans.append(t)
            for x in adj[t]:
                if visited[x] == False:
                    pq.append(x)
                    visited[x] = True
                    
        return ans