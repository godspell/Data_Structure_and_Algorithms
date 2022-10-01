class Solution(object):
    def maxSubArray(self, nums):
        maxsum = nums[0]
        curr_sum = 0
        for i in nums:
            curr_sum += i
            maxsum = max(curr_sum, maxsum)
            if curr_sum < 0:
                curr_sum = 0
        
        return maxsum