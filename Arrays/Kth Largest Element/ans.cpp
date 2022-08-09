class Solution {
public:
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    int partition(vector<int> &nums, int lo, int hi){
	  int pivot = nums[hi];
	  int i = lo - 1;
	
	  for(int j = lo; j<hi; j++){
		 if(nums[j] < pivot){
			i++;
			swap(nums, i, j);
		 }
	  }
	
	  i++;
	  swap(nums, i, hi);
	  return i;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
	if(n == 1) return nums[0];
	
	int lo = 0, hi = n - 1;
	int target = n - k;
	 while(lo <= hi){
		int pivot = partition(nums, lo, hi);
		if(pivot < target){
			lo = pivot + 1;
		}
		else if(pivot > target){
			hi = hi - 1;
        }
		else{
			return nums[pivot];
		}
     }
        return -1;
    }
};