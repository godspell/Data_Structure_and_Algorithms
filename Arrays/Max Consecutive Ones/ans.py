class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        n = len(nums)
        ans, count = 0, 0
        for i in range(0, n):
            if nums[i] == 1:
                count += 1
                ans = max(ans, count)
            else: count = 0
        
        return ans