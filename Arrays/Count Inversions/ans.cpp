 class Solution{
  public:
    
    long long merge(long long arr[], long long left, long long mid, long long right){
        
        long long n1 = mid - left + 1;
        long long n2 = right - mid;
        long long inv_count = 0;
        
        long long arr1[n1] , arr2[n2];
        
        for(long long i = 0; i<n1; i++){
           arr1[i] = arr[left+i]; 
        }
        for(long long i = 0; i<n2; i++){
            arr2[i] = arr[mid + i + 1];
        }
        
        long long p = 0, q = 0, r = left;
        while(p < n1 && q < n2){
            if(arr1[p] <= arr2[q]){
                arr[r++] = arr1[p++];
            }
            else{
                inv_count += n1 - p;
                arr[r++] = arr2[q++];
            }
        }
        
        while(p < n1){
            arr[r++] = arr1[p++];
        }
        
        while(q < n2){
            arr[r++] = arr2[q++];
        }
        
        return inv_count;
    }
    
    long long merge_sort(long long arr[], long long left, long long right){
        long long total_inv = 0;
        if(left < right){
            long long mid = left + (right - left)/2;
            total_inv += merge_sort(arr, left, mid);
            total_inv += merge_sort(arr, mid+1, right);
            total_inv += merge(arr, left, mid, right);
        }
        return total_inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return merge_sort(arr, 0, N-1);
    }

};