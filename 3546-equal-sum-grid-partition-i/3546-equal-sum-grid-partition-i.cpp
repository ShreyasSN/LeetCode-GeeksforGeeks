class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long sum = 0;
        for(int i=0; i<n; i++) {
            long long cur = accumulate(grid[i].begin(), grid[i].end(), 0ll);
            sum += cur;
        }
        long long x = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                x += grid[i][j];
            }
            if(x == sum - x) return true;
        }

        x = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                x += grid[j][i];
            }
            if(x == sum - x) return true;
        }

        return false;
    }
};