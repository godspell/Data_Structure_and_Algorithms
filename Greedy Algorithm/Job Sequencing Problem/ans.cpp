class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool mycompare(Job &a, Job &b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<Job> a;
        int mx = -1;
        for(int i = 0; i<n; i++){
            mx = max(mx, arr[i].dead);
            a.push_back(arr[i]);
        }
        sort(a.begin(), a.end(), mycompare);
        int ans = 0, count = 0;
        vector<int> visited(mx+1, -1);
        for(int i = 0; i<n; i++){
            int dead = a[i].dead;
            int profit = a[i].profit;
            int idx = dead;
            while(idx != 0){
                if(visited[idx] == -1) break;
                idx--;
            }
            if(idx != 0){
                ans += profit;
                count++;
                visited[idx] = 1;
            }
        }
        
        return {count, ans};
    } 
};