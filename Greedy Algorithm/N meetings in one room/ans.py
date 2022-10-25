class Solution:
    
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,n,start,end):
        # code here
        li = []
        for i in range(n):
            li.append([start[i], end[i]])
        
        li = sorted(li, key = lambda x: (x[1], x[0]))
        ans, curr = 1, li[0][1]
        for i in range(1, n):
            if li[i][0] > curr:
                ans += 1
                curr = li[i][1]
            
        return ans