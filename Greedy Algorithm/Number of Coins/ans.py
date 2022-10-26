class Solution(object):
    def coinChange(self, coins, amount):
        
        n = len(coins)
        dp = [10001]*(amount+1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for j in range(n):
                if i - coins[j] >= 0:
                    if dp[i-coins[j]] != 10001:
                        dp[i] = min(dp[i], dp[i-coins[j]] + 1)
                    
        return -1 if dp[-1] == 10001 else dp[amount]