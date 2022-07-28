class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> rows[9];
        set<char> cols[9];
        set<char> box[9][9];
        
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j] == '.')
                    continue;
                
                if(rows[i].find(board[i][j]) != rows[i].end() ||
                   cols[j].find(board[i][j]) != cols[j].end() ||
                   box[i/3][j/3].find(board[i][j]) != box[i/3][j/3].end())
                    return false;
                
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                box[i/3][j/3].insert(board[i][j]);
            }
        }
        
        return true;
    }
};