class Solution(object):
    def isBipartite(self, graph):
        n = len(graph)
        color = [-1]*n

        for i in range(n):
            if color[i] == -1:
                color[i] = 1
                queue = [i]
                while len(queue) > 0:
                    t = queue.pop(0)
                    for x in graph[t]:
                        if color[x] == -1:
                            color[x] = 1 - color[t]
                            queue.append(x)
                        elif color[x] == color[t]:
                            return False
        
        return True