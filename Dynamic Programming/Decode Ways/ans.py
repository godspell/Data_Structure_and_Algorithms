class Solution(object):
    def numDecodings(self, s):
        n = len(s)
        dp, dp1, dp2 = 0, 1, 0
        
        for i in range(n - 1, -1, -1):
            if s[i] != '0':
                dp += dp1
                
            if i+1 < n and (s[i] == '1' or s[i] == '2' and s[i+1] <= '6'):
                dp += dp2
                    
            dp2 = dp1
            dp1 = dp
            dp = 0
            
        return dp1
    