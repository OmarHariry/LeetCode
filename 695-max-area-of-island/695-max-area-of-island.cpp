class Solution {
public:
    int dfs(vector<vector<int>>&grid, int i,int j, int count){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == 0)
            return count;
        
        grid[i][j] = 0;
        ++count;
        
        count = dfs(grid,i+1,j,count);
        count = dfs(grid,i-1,j,count);
        count = dfs(grid,i,j+1,count);
        count = dfs(grid,i,j-1,count);
        
        return count;
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j] == 1){
                    int count = dfs(grid,i,j,0);
                    maxArea = max(count,maxArea);
                }
            }
        }
        return maxArea;
    }
};