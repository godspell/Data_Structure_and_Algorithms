class Solution(object):
    def fourSum(self, nums, target):
        ans = []
        n = len(nums)
        if n < 4:
            return ans
        
        nums.sort()
        for i in range(0, n - 3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, n - 2):
                if j>i+1 and nums[j] == nums[j-1]:
                    continue
                sum2 = target - nums[i] - nums[j]
                if(sum2 > nums[n-1] + nums[n-2]): continue
                if(sum2 < nums[j+1] + nums[j+2]): break
                k, l = j+1, n - 1
                while k < l:
                    sum = nums[k] + nums[l]
                    if sum == sum2:
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        while k+1<l and nums[k] == nums[k+1]:
                            k += 1
                        while l-1 > k and nums[l] == nums[l-1]:
                            l -= 1
                        k += 1
                        l -= 1
                    elif sum > sum2:
                        l -= 1
                    else:
                        k += 1
        
        return ans
                            
                    
        