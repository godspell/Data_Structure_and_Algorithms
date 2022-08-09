class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int ans = 1;
        for(int g = 0; g<n; g++){
            for(int i = 0, j = g; j<n; i++, j++){
               if(g == 0){
                   dp[i][j] = 1;
               }
               else if(g == 1){
                   if(s[i] == s[j]){
                       dp[i][j] = 2;
                   }
                   else{
                       dp[i][j] = 1;
                   }
               }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                    else{
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
             }
        }
        return n - dp[0][n-1];
    }
};