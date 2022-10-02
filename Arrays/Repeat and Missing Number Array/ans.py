class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def repeatedNumber(self, arr):
        n = len(arr)
        x = 0
        for i in range(0, n):
            x ^= arr[i]
        for i in range(1, n+1):
            x ^= i
        
        a, b = 0, 0
        rsb = x & (-x)
        for i in range(0, n):
            if (rsb & arr[i]) == 0:
                a ^= arr[i]
            else:
                b ^= arr[i]
        
        for i in range(1, n+1):
            if (rsb & i) == 0:
                a ^= i
            else:
                b ^= i
        
        for i in range(0, n):
            if a == arr[i]:
                return [a, b]
            elif b == arr[i]:
                return [b, a]
        
        return [-1, -1]
