class Solution(object):
    def dfs(self, i, edges, visited, st):
        st[i] = 1
        if visited[i] == 0:
            visited[i] = 1
            for x in edges[i]:
                if visited[x] == 0 and self.dfs(x, edges, visited, st):
                    return True
                if st[x] == 1:
                    return True
        
        st[i] = 0
        return False

    def canFinish(self, n, pre):
        edges = defaultdict(list)
        for x in pre:
            edges[x[1]].append(x[0])
        
        visited = [0]*n
        st = [0]*n

        cycle = False
        for i in range(n):
            if visited[i] == 0 and self.dfs(i, edges, visited, st):
                cycle = True
                break
        
        return not cycle