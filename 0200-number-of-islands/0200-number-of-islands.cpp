class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int rows, int cols) {
        if(i >= rows || j >= cols ||  i < 0 || j < 0|| grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        dfs(grid, i+1, j, rows, cols);
        dfs(grid, i, j+1, rows, cols);
        dfs(grid, i-1, j, rows, cols);
        dfs(grid, i, j-1, rows, cols); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[i].size();++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    dfs(grid, i, j, grid.size(), grid[i].size());
                }
            }
        }
        return islands;
    }
};