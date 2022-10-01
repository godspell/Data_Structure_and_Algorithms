class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int curr = 0;
        int currmax = INT_MIN;
        for(int i=0; i<n; i++){
          curr += arr[i];
          currmax = max(currmax, curr);
          if(curr<0) curr = 0;
        }
        
        return currmax;
    }
};