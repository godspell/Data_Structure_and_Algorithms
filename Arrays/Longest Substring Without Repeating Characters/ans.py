class Solution(object):
    def lengthOfLongestSubstring(self, s):
        n = len(s)
        if s == 1:
            return 1
        
        ans, start = 0, -1
        freq = [-1]*256
        for i in range(n):
            if freq[s[i]] > start:
                start = freq[s[i]]
                
            freq[s[i]] = i
            ans = max(ans, i - start)
            
        return ans