from collections import deque
class Solution:
    
    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        # Code here
        indeg = [0]*V
        ans = []
        for i in range(V):
            for x in adj[i]:
                indeg[x] += 1
        
        pq = deque()
        for i in range(V):
            if indeg[i] == 0:
                pq.append(i)
                
        while(len(pq)) > 0:
            t = pq.popleft()
            ans.append(t)
            for x in adj[t]:
                indeg[x] -= 1
                if indeg[x] == 0:
                    pq.append(x)
            
        return ans