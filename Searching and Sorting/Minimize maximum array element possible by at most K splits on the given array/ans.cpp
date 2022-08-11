#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int n, int mid, int k){
    int count = 0;
    for(int i = 0; i<n; i++){
        count += ((arr[i] - 1)/mid);
    }

    return count <= k;
}

int find_minimum(vector<int> &arr, int n, int k){
    int lo = 1;
    int hi = *max_element(arr.begin(), arr.end());
    int ans = 0;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(possible(arr, n, mid, k)){
            ans = mid;
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = find_minimum(arr, n, k);
    cout<<ans<<endl;
    return 0;
}