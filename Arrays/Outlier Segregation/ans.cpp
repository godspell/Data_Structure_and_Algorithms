#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int find_swap(vector<int> &arr){
    int n = arr.size();
    int non_zeros = 0, count = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] != 0) non_zeros++;
    }

    for(int i = 0; i<non_zeros; i++){
        if(arr[i] == i+1) continue;

        if(arr[i] != 0){
            int j = i+1;
            while(arr[j] != 0) j++;

            swap(arr, i, j);
            count++;
        }

        int j = i+1;
        while(arr[j] != i+1) j++;

        swap(arr, i, j);
        count++;
    }

    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int ans = find_swap(arr);
    cout<<ans<<endl;
    return 0;
}