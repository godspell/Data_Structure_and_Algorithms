class Solution{
  public:
  int findPlatform(int arr[], int dept[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dept, dept+n);
    	
    	int i=0, j=0, result=0, count =0;
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dept[j])
    	    {
    	        count++;
    	        i++;
    	    }
    	    else
    	    {
    	        count--;
    	        j++;
    	    }
    	    result = max(result, count);
    	}
    	return result;
    }
};
