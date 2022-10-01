class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        bool flag = true;
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i]<arr[i+1])
            {
                flag = false;
                sort(arr.begin()+i+1, arr.end());
                int k = i+1;
                while(arr[i] >= arr[k])
                k++;
                swap(arr[k], arr[i]);
                break;
            }
        }
        if(flag)
        {
            sort(arr.begin(), arr.end());
        }
    }
};