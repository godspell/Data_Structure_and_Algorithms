int minMovesRequired(int n, Cell start, Cell end) {
	vector<vector<int>> shortestPath(n + 1, vector<int> (n + 1, - 1));
	queue<pair<int, int>> reachableBlocks;
	reachableBlocks.push({start.x, start.y});
	shortestPath[start.x][start.y] = 0;
	while(!reachableBlocks.empty()) {
		pair<int, int> currBlock = reachableBlocks.front();
		int x = currBlock.first;
		int y = currBlock.second;
		reachableBlocks.pop();
		for (int i = max(1, x - 2); i <= min(n, x + 2); i++) {
			for (int j = max(1, y - 2); j <= min(n, y + 2); j++) {
				if(abs(x - i) + abs(y - j) == 3 && x != i && y != j && shortestPath[i][j] == - 1) {
					shortestPath[i][j] = shortestPath[x][y] + 1;
					reachableBlocks.push({i, j});
				}
			}
		}
	}
	return shortestPath[end.x][end.y];
}                       