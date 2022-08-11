bool dfs(int i, vector<vector<int>> &edges, vector<int> &visited, int parent){
	visited[i] = true;
	for(auto it : edges[i]){
		if(it != parent){
			if(visited[it]) return true;
			
			if(!visited[it] && dfs(it, edges, visited, i)){
				return true;
			}
		}
	}
	
	return false;
}

bool isCyclic(vector<vector<int>> &edges) {
    // add your logic here
	int n = edges.size();
	vector<int> visited(n, 0);
	bool flag = false;
	for(int i = 0; i<n; i++){
		if(!visited[i] && dfs(i, edges, visited, -1)){
			flag = true;
			break;
        }
	}
	
	return flag;
}