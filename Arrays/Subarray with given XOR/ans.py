from collections import defaultdict
class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        mp = defaultdict(bool)
        count, curr = 0, 0
        mp[0] = 1
        
        for x in A:
            curr = curr ^ x
            if mp[curr^B]:
                count += mp[curr ^ B]
            mp[curr] += 1
        
        return count