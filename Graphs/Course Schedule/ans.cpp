class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &pre)
    {
        vector<vector<int>> edges(n);
        vector<int> indeg(n, 0);
        for(auto it : pre){
            edges[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        int count = 0;
        queue<int> pq;
        for(int i = 0; i<n; i++){
            if(indeg[i] == 0) pq.push(i); 
        }
        while(!pq.empty()){
            int t = pq.front();
            pq.pop();
            count++;
            for(int it : edges[t]){
                indeg[it]--;
                if(indeg[it] == 0) pq.push(it);
            }
        }
        if(count == n) return true;
        return false;
    }
};