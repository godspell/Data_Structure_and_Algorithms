class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       int n = nums.size();
       vector<vector<int>> ans;
       if(n < 4) return ans;
       sort(nums.begin(), nums.end());
       
       for(int i = 0; i<n-3; i++){
           if(i > 0 && nums[i] == nums[i-1]) continue;
           long long int sum3 = target - nums[i];
           for(int j = i + 1; j<n-2; j++){
               if(j>i+1 && nums[j] == nums[j-1]) continue;
               long long int sum2 = sum3 - nums[j];
               if(sum2 > nums[n-2] + nums[n-1]) continue;
               if(sum2 < nums[j+1] + nums[j+2]) break;
               int k = j + 1, l = n - 1;
               while(k < l){
                   long long int sum = nums[k] + nums[l];
                   if(sum == sum2){
                       ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                       while(k+1 < l && nums[k] == nums[k+1])k++;
                       while(l-1 > k && nums[l] == nums[l-1])l--;
                       k++, l--;
                   }
                   else if(sum > sum2){
                       l--;
                   }
                   else{
                       k++;
                   }
               }
           }
       }
        
        return ans;
    }
};