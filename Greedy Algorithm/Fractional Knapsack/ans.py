class Solution:    
    #Function to get the maximum total value in the knapsack.
    def fractionalknapsack(self, W,Items,n):
        arr = []
        for i in range(n):
            arr.append([Items[i].value/Items[i].weight, Items[i].value, Items[i].weight])
        
        arr.sort(key = lambda x : x[0], reverse = True)
        amount = 0
        
        for i in range(n):
                if W >= arr[i][2]:
                    amount += arr[i][1]
                    W -= arr[i][2]
                else:
                    ratio = arr[i][1]/arr[i][2]
                    amount += ratio*W
                    w = 0
                    break
            
        return amount