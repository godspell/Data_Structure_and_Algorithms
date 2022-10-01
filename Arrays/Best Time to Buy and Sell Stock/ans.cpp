class Solution {
public:
    int maxProfit(vector<int>& arr) {
         int profit = 0;
         int least = arr[0];
            for(int i=1; i<arr.size(); i++){
                    if(arr[i] < least)
                     least = arr[i];
                    
                    profit = max(profit, arr[i] - least);
            }
                    
         return profit;           
    }
};