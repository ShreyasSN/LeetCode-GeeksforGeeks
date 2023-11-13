class Solution {
    int rows;
    int cols;

    void dfs(vector<vector<char>>& a, int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= cols) return;

        if(a[i][j] != 'O') return;

        a[i][j] = '#';

        dfs(a, i+1, j);
        dfs(a, i-1, j);
        dfs(a, i, j+1);
        dfs(a, i, j-1);
    }

public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        rows = board.size();
        cols = board[0].size();

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(i == 0 || j == 0 || i == rows - 1 || j == cols-1){
                    dfs(board, i, j);
                }
            }
        }

        for(int i=0; i<rows; i++)
         for(int j=0; j<cols; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
         }
        
    }
};