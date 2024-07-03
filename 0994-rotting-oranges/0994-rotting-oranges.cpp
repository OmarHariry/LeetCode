class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, minutes = 0;
        queue<pair<int, int>>q;
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 1)
                    ++fresh;
                if (grid[i][j] == 2) {
                    q.push({ i, j });
                    visited[i][j] = 1;
                }
            }
        }

        if (fresh == 0)
            return 0;
        if (q.empty())
            return -1;

        vector<int> DIR = { 0, 1, 0, -1, 0 };
        while (!q.empty()) {
            bool flag = false;
            int size = q.size();
            
            while(size--) {
                
                auto [r, c] = q.front();
                q.pop();
                visited[r][c] = 1;
                
                for (int i = 0; i < 4; ++i) {
                    int nr = r + DIR[i], nc = c + DIR[i + 1];
                    if (nr >= ROWS || nr < 0 || nc >= COLS || nc < 0
                        || visited[nr][nc] == 1 || grid[nr][nc] == 0)
                        continue;
                    if (grid[nr][nc] == 1) {
                        flag = true;
                        --fresh;
                        grid[nr][nc] = 2;
                        q.push({ nr, nc });
                    }
                }
            }
            if (flag) ++minutes;
        }
        return fresh == 0 ? minutes : -1;
    }
};