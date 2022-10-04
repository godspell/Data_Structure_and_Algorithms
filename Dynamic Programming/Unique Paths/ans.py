class Solution(object):
    def solve(self, i, j, n, m, dp):
        if i > n - 1 or j > m - 1:
            return 0
        if i == n - 1 and j == m - 1:
            return 1
        
        if dp[i][j] != -1:
            return dp[i][j]
        ans = 0;
        ans += self.solve(i, j+1, n, m, dp)
        ans += self.solve(i+1, j, n, m, dp)
        
        dp[i][j] = ans
        return ans
    
    def uniquePaths(self, m, n):
        dp =  [[-1]*n for _ in range(m)]
        return self.solve(0, 0, m, n, dp)
        