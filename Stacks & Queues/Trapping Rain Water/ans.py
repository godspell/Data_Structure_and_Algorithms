class Solution(object):
    def trap(self, height):
        n = len(height)
        st = []
        ans = 0
        for i in range(0, n):
            while st and height[st[-1]] < height[i]:
                t = st[-1]
                st.pop()
                if len(st) == 0:
                    break
                h = min(height[st[-1]], height[i]) - height[t]
                l = i - st[-1] - 1
                ans += (l*h)
                
            st.append(i)
        
        return ans
        