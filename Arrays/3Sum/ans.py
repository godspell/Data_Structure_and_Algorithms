class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        n = len(nums)
        ans = []
        
        for i in range(0, n - 1):
            if i>0 and nums[i] == nums[i-1]: continue
            j, k = i+1, n - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum < 0:
                    j += 1
                elif sum > 0:
                    k -= 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    while j + 1 < k and nums[j+1] == nums[j]: j += 1
                    while k - 1 > j and nums[k] == nums[k-1]: k -= 1
                    j += 1
                    k -= 1
                    
        return ans