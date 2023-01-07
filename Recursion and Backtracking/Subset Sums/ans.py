def solve(arr, idx, sum, ans):
    if idx == len(arr):
        ans.append(sum)
        return
    
    solve(arr, idx+1, sum + arr[idx], ans)
    solve(arr, idx+ 1, sum, ans)
    
class Solution:
    def subsetSums(self, arr, N):
        # code here
        ans = []
        
        solve(arr, 0, 0, ans)
        return ans