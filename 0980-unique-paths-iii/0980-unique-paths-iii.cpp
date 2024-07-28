class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int  m = grid.size(),  n = grid[0].size();
        int empty = 1;
        int sx, sy, ex, ey;
        int res = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) empty++;
                else if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }
        dfs(grid, sx, sy, res, empty);
        return res;
    }

    void dfs(vector<vector<int>>& g, int i, int j, int& res, int e){
        if(i<0 || i>g.size()-1 || j<0 || j>g[0].size()-1 || g[i][j] < 0) return;
        
        if(g[i][j] == 2){
            if(e == 0) res++;
            return;
        }

        g[i][j] = -2;
        e--;
        dfs(g, i + 1, j, res, e);
        dfs(g, i - 1, j, res, e);
        dfs(g, i, j + 1, res, e);
        dfs(g, i, j - 1, res, e);
        g[i][j] = 0;
        e++;
    }
};