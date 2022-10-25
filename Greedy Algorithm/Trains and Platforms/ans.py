class Solution:    
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self,n,arr,dep):
        # code here
        arr.sort()
        dep.sort()
        ans, curr, i, j = 0, 0, 0, 0
        
        while i < n and j < n:
            if arr[i] <= dep[j]:
                curr += 1
                i += 1
            else:
                curr -= 1
                j += 1
            ans = max(ans, curr)
        
        return ans