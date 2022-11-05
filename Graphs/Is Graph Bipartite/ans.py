class Solution(object):
    def isBipartite(self, graph):
        
        def dfs(i, curr):
            if i in seen:
                return seen[i] != curr

            curr ^= 1
            seen[i] = curr
            for x in graph[i]:
                if not dfs(x, curr):
                    return False 
            return True
            
        seen = {}
        for x in range(len(graph)):
            if x not in seen and not dfs(x, 0):
                return False
        
        return True