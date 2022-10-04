class Solution {
public:
    int dp[100][100];
    int solve(int i, int j, int n, int m){
        if(i > n - 1 || j > m - 1) return 0;
        if(i == n - 1 && j == m - 1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        ans += solve(i, j+1, n, m);
        ans += solve(i+1, j, n, m);
        
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n);
    }
};