class Solution {
public:
    int bfs(vector<vector<int>> &grid, int i, int j, int area) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return area;
        
        grid[i][j] = 0;
        ++area;
        
        area = bfs(grid, i+1, j, area);
        area = bfs(grid, i, j+1, area);
        area = bfs(grid, i-1, j, area);
        area = bfs(grid, i, j-1, area);
        
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[i].size();++j) {
                if(grid[i][j] == 1) {
                    int area = bfs(grid, i, j, 0);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};