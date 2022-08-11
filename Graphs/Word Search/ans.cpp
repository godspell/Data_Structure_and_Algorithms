bool dfs(vector<vector<char>> &board, string &word, int i, int j, int k){
	if(k == word.size()) return true;
	if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || board[i][j] != word[k]){
		return false;
	}
	
	board[i][j] = '#';
	bool flag = false;
	flag = dfs(board, word, i+1, j, k+1) ||
		   dfs(board, word, i-1, j, k+1) ||
		   dfs(board, word, i, j+1, k+1) ||
		   dfs(board, word, i, j-1, k+1);
	board[i][j] = word[k];
	
	return flag;
}

bool wordExists(vector<vector<char>> &board, string word) {
    // add your logic here
	if(word.size() == 0) return 0;
	for(int i = 0; i<board.size(); i++){
		for(int j = 0; j<board[0].size(); j++){
			if(board[i][j] == word[0] && dfs(board, word, i, j, 0)){
				return true;
			}
		}
	}
	
	return false;
}