class Solution(object):
    def dfs(self, node, visited):
        if node is None:
            return None
        if node.val in visited:
            return visited[node.val]
        
        clone = Node(node.val)
        visited[node.val] = clone
        for x in node.neighbors:
            clone.neighbors.append(self.dfs(x, visited))
        
        return clone
        
    def cloneGraph(self, node):
        return self.dfs(node, {})