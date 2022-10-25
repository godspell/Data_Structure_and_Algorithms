class Solution:
    
    #Function to find the maximum profit and the number of jobs done.
    def JobScheduling(self,Jobs,n):
        Jobs.sort(key = lambda x : x.profit, reverse = True)
        jb, tp = 0, 0
        
        seen = [0]*(101)
        for i in range(n):
            idx = Jobs[i].deadline
            while idx != 0:
                if seen[idx] == 0:
                    break
                idx -= 1
            
            if idx != 0:
                jb += 1
                tp += Jobs[i].profit
                seen[idx] = 1
            
        return [jb, tp]
