class Solution {
public:
    void dfs(vector<vector<int>>&image, int i,int j, int originalColor,int color){
        if(i >= image.size() || i < 0 || j >= image[0].size() || j < 0 || image[i][j] != originalColor)
            return;
        
        
        image[i][j] = color;
        
        dfs(image, i+1,j,originalColor,color);
        dfs(image,i,j+1,originalColor,color);
        dfs(image,i-1,j,originalColor,color);
        dfs(image,i,j-1,originalColor,color);
        
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            dfs(image,sr,sc, image[sr][sc],color);
        return image;
    }
};