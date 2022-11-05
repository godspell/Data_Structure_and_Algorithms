class Solution{
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<char>> &grid, int i, int j){
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++){
            int x = i + dir[k];
            int y = j + dir[k + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1'){
                dfs(grid, x, y);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};