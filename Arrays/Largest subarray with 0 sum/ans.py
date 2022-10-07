class Solution:
    def maxLen(self, n, arr):
        #Code here
        sum, ans = 0, 0
        mp = {}
        mp[0] = -1
        
        for i in range(0, n):
            sum += arr[i]
            if sum in mp:
                ans = max(ans, i - mp[sum])
            else:
                mp[sum] = i
        return ans