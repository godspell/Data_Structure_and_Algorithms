    bool isCyclic(int n, vector<int> adj[]) {
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for(auto it : adj[i])
        indeg[it]++;
    }
    queue<int> pq;
    for(int i=0; i<n; i++)
    {
        if(indeg[i] == 0)
        pq.push(i);
    }
    int count = 0;
    while(!pq.empty())
    {
        int t = pq.front();
        count++;
        pq.pop();
        for(auto it : adj[t])
        {
            indeg[it]--;
            if(indeg[it] == 0)
            pq.push(it);
        }
    }
    if(count == n)
    return false;

    return true;
    }