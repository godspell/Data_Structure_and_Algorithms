class Solution {
public:
    int empty = 1, ans = 0;
    void dfs(vector<vector<int>> &grid, int i, int j, int count){
        if(i < 0 || i >= grid.size() || j<0 || j>= grid[0].size() || grid[i][j] == -1){
            return;
        }
        
        if(grid[i][j] == 2){
           if(count == empty){
               ans++;
           }
           return;
        }
           
        grid[i][j] = -1;
        dfs(grid, i+1, j, count+1);
        dfs(grid, i-1, j, count+1);
        dfs(grid, i, j+1, count+1);
        dfs(grid, i, j-1, count+1);
        
        grid[i][j] = 0;
    }
                   
    int uniquePathsIII(vector<vector<int>>& grid) {
        empty = 1;
        int n = grid.size();
        int m = grid[0].size();
        int x = -1, y = -1;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    x = i, y = j;
                }
                else if(grid[i][j] == 0){
                    empty++;
                }
            }
        }
        
        dfs(grid, x, y, 0);
        return ans;
    }
};