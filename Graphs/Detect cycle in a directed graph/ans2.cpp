bool dfs(int i, vector<vector<int>> &edges, vector<int> &visited, vector<int> &st){
   st[i] = 1;
	if(!visited[i]){
		visited[i] = 1;
		for(auto it : edges[i]){
		  if(!visited[it] && dfs(it, edges, visited, st)){
			  return true;
		  }
			
		  if(st[it]) return true;
		}
	}
		
	st[i] = false;	
	return false;	
}

bool isCyclic(vector<vector<int>> &adj) {
    // add your logic here
	int n = adj.size();
	vector<int> visited(n, 0);
	vector<int> st(n, 0);
	bool flag = false;
	for(int i = 0; i<n; i++){
		if(!visited[i] && dfs(i, adj, visited, st)){
			flag = true;
			break;
		}
	}
	
	return flag;
}