class Solution {
public:
    int dp[13][10001];
    int solve(int i, vector<int>&coins, int amount){
        if(i == coins.size() || amount < 0){
            return (amount == 0) ? 0 : INT_MAX/2;
        }
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        if(coins[i] > amount){
           dp[i][amount] = 0 + solve(i+1, coins, amount); 
        }
        else{
            int take = 1 + solve(i, coins, amount - coins[i]);
            int dont = 0 + solve(i+1, coins, amount);
            dp[i][amount] = min(take, dont);
        }
        
        return dp[i][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, coins, amount);
        if(ans == INT_MAX/2) return -1;
        return ans;
    }
};