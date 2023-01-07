class Solution
{
public:
    vector<int> ans;
    void solve(vector<int> &arr, int idx, int sum){
        if(idx == arr.size()){
            ans.push_back(sum);
            return;
        }
        solve(arr, idx + 1, sum + arr[idx]);
        solve(arr, idx+1, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        solve(arr, 0, 0);
        return ans;
    }
};