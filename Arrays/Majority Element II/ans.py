class Solution(object):
    def majorityElement(self, nums):
        n = len(nums)
        num1, num2, count1, count2 = -1, -1, 0, 0
        for i in nums:
            if i == num1:
                count1 += 1
            elif i == num2:
                count2 += 1
            elif count1 == 0:
                num1 = i
                count1 = 1
            elif count2 == 0:
                num2 = i
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1
        
        count1, count2 = 0, 0
        for i in nums:
            if num1 == i:
                count1 += 1
            elif num2 == i:
                count2 += 1
        
        ans = []
        if count1 > n/3:
            ans.append(num1)
        if count2 > n/3:
            ans.append(num2)
        
        return ans