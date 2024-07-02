class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int ROWS = mat.size(), COLS = mat[0].size();
        for(int i=0;i<ROWS;++i) {
            for(int j=0;j<COLS;++j) {
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }
        // {0,1} -> down
        // {1,0} -> right
        // {0,-1} -> top
        // {-1,0} -> left 
        vector<int> DIR = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for(int i=0;i<4;++i) {
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || mat[nr][nc] != -1)
                    continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return mat;
    }
};