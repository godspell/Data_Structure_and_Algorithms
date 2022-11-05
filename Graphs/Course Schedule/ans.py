class Solution(object):
    def canFinish(self, courses, pre):
        edges = defaultdict(list)
        indeg = [0]*courses

        for e in pre:
            edges[e[1]].append(e[0])
            indeg[e[0]] += 1
        
        pq = deque()
        for i in range(courses):
            if indeg[i] == 0:
                pq.append(i)
        
        count = 0
        while(len(pq)) > 0:
            t = pq.popleft()
            count += 1
            for x in edges[t]:
                indeg[x] -= 1
                if indeg[x] == 0:
                    pq.append(x)
        
        return count == courses